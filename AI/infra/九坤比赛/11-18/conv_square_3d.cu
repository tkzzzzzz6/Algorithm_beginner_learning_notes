#include <cuda_runtime.h>
#include <stddef.h>

namespace {

constexpr int kTileX = 32;
constexpr int kTileY = 4;
constexpr int kTileZ = 4;

__device__ size_t volume_index(int z, int y, int x, int size) {
    return (static_cast<size_t>(z) * size + y) * size + x;
}

__device__ bool in_bounds(int coordinate, int size) {
    return coordinate >= 0 && coordinate < size;
}

template <int K>
__global__ void convolve_tiles(const float* input, const float* filter,
                               float* output, int size) {
    constexpr int kRadius = K / 2;
    constexpr int kWidth = kTileX + K - 1;
    constexpr int kHeight = kTileY + K - 1;
    constexpr int kDepth = kTileZ + K - 1;
    constexpr int kPlane = kWidth * kHeight;
    __shared__ float tile[kDepth * kPlane];
    __shared__ float weights[K * K * K];

    const int lane = threadIdx.x;
    const int warp = threadIdx.y;
    const int x0 = blockIdx.x * kTileX;
    const int y0 = blockIdx.y * kTileY;
    const int z0 = blockIdx.z * kTileZ;

    // Each warp loads a contiguous input row and its halo.
    for (int row = warp; row < kDepth * kHeight; row += kTileY) {
        const int z = z0 + row / kHeight - kRadius;
        const int y = y0 + row % kHeight - kRadius;
        const bool valid_row = in_bounds(z, size) && in_bounds(y, size);
        for (int col = lane; col < kWidth; col += kTileX) {
            const int x = x0 + col - kRadius;
            tile[row * kWidth + col] = valid_row && in_bounds(x, size)
                ? input[volume_index(z, y, x, size)] : 0.0f;
        }
    }
    for (int tap = warp * kTileX + lane; tap < K * K * K;
         tap += kTileX * kTileY) {
        weights[tap] = filter[tap];
    }
    __syncthreads();

    const int x = x0 + lane;
    const int y = y0 + warp;
    if (x >= size || y >= size) return;

    float sums[kTileZ] = {};
    for (int fy = 0; fy < K; ++fy) {
        for (int fx = 0; fx < K; ++fx) {
            // Reuse the depth samples across the four outputs of this thread.
            float samples[K + kTileZ - 1];
            const int base = (warp + fy) * kWidth + lane + fx;
            #pragma unroll
            for (int z = 0; z < K + kTileZ - 1; ++z) {
                samples[z] = tile[z * kPlane + base];
            }
            #pragma unroll
            for (int fz = 0; fz < K; ++fz) {
                const float weight = weights[(fz * K + fy) * K + fx];
                #pragma unroll
                for (int dz = 0; dz < kTileZ; ++dz) {
                    sums[dz] = fmaf(samples[fz + dz], weight, sums[dz]);
                }
            }
        }
    }

    #pragma unroll
    for (int dz = 0; dz < kTileZ; ++dz) {
        const int z = z0 + dz;
        if (z < size) output[volume_index(z, y, x, size)] = sums[dz];
    }
}

__global__ void convolve_generic(const float* input, const float* filter,
                                 float* output, int size, int K, size_t count) {
    const int radius = K / 2;
    const size_t step = static_cast<size_t>(gridDim.x) * blockDim.x;
    for (size_t i = static_cast<size_t>(blockIdx.x) * blockDim.x + threadIdx.x;
         i < count; i += step) {
        const int x = static_cast<int>(i % size);
        const int y = static_cast<int>(i / size % size);
        const int z = static_cast<int>(i / size / size);
        float sum = 0.0f;
        for (int fz = 0; fz < K; ++fz) {
            const int iz = z + fz - radius;
            if (!in_bounds(iz, size)) continue;
            for (int fy = 0; fy < K; ++fy) {
                const int iy = y + fy - radius;
                if (!in_bounds(iy, size)) continue;
                for (int fx = 0; fx < K; ++fx) {
                    const int ix = x + fx - radius;
                    if (!in_bounds(ix, size)) continue;
                    sum = fmaf(input[volume_index(iz, iy, ix, size)],
                               filter[volume_index(fz, fy, fx, K)], sum);
                }
            }
        }
        output[i] = sum;
    }
}

}  // namespace

extern "C" void solution(const float* A, const float* B, float* C,
                         size_t size, size_t K) {
    if (size == 0 || K == 0) return;

    const int side = static_cast<int>(size);
    const dim3 block(kTileX, kTileY);
    const dim3 grid(static_cast<unsigned int>(1 + (size - 1) / kTileX),
                    static_cast<unsigned int>(1 + (size - 1) / kTileY),
                    static_cast<unsigned int>(1 + (size - 1) / kTileZ));
    switch (K) {
        case 3: convolve_tiles<3><<<grid, block>>>(A, B, C, side); break;
        case 5: convolve_tiles<5><<<grid, block>>>(A, B, C, side); break;
        case 7: convolve_tiles<7><<<grid, block>>>(A, B, C, side); break;
        case 9: convolve_tiles<9><<<grid, block>>>(A, B, C, side); break;
        case 11: convolve_tiles<11><<<grid, block>>>(A, B, C, side); break;
        default: {
            constexpr unsigned int kThreads = 256;
            constexpr unsigned int kMaxBlocks = 65535;
            const size_t count = size * size * size;
            const size_t blocks = 1 + (count - 1) / kThreads;
            const auto launch_blocks = static_cast<unsigned int>(
                blocks < kMaxBlocks ? blocks : kMaxBlocks);
            convolve_generic<<<launch_blocks, kThreads>>>(
                A, B, C, side, static_cast<int>(K), count);
        }
    }
}
