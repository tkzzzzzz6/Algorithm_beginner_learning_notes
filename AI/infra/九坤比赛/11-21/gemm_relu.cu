#include <cuda_runtime.h>
#include <stddef.h>
#include <stdint.h>

namespace {

constexpr unsigned kThreadSide = 16;
constexpr unsigned kOutputsPerThread = 4;
constexpr unsigned kTile = kThreadSide * kOutputsPerThread;
constexpr unsigned kDepth = 16;

template <bool FullTiles>
__device__ __forceinline__ void load_tile(
    const float* source, float (&tile)[kDepth][kTile + 1],
    size_t rows, size_t stride, size_t first_row, size_t first_k) {
    // Neighboring threads read contiguous groups of four reduction elements.
    const unsigned local_row = threadIdx.x / (kDepth / 4);
    const unsigned local_k = 4 * (threadIdx.x % (kDepth / 4));
    const size_t row = first_row + local_row;
    const size_t k = first_k + local_k;
    if (FullTiles) {
        const float4 values = *reinterpret_cast<const float4*>(source + row * stride + k);
        tile[local_k][local_row] = values.x;
        tile[local_k + 1][local_row] = values.y;
        tile[local_k + 2][local_row] = values.z;
        tile[local_k + 3][local_row] = values.w;
    } else {
        #pragma unroll
        for (unsigned i = 0; i < 4; ++i) {
            tile[local_k + i][local_row] =
                row < rows && k + i < stride ? source[row * stride + k + i] : 0.0f;
        }
    }
}

template <bool FullTiles>
__global__ void gemm_relu(const float* A, const float* W, const float* b,
                          float* C, size_t B, size_t N, size_t M) {
    // Padding the transposed shared-memory tiles reduces bank conflicts on load.
    __shared__ float activations[kDepth][kTile + 1];
    __shared__ float weights[kDepth][kTile + 1];
    const unsigned lane_x = threadIdx.x % kThreadSide;
    const unsigned lane_y = threadIdx.x / kThreadSide;
    const size_t tile_row = static_cast<size_t>(blockIdx.y) * kTile;
    const size_t tile_col = static_cast<size_t>(blockIdx.x) * kTile;
    float sums[kOutputsPerThread][kOutputsPerThread] = {};

    for (size_t k0 = 0; k0 < N; k0 += kDepth) {
        load_tile<FullTiles>(A, activations, B, N, tile_row, k0);
        load_tile<FullTiles>(W, weights, M, N, tile_col, k0);
        __syncthreads();

        #pragma unroll
        for (unsigned k = 0; k < kDepth; ++k) {
            float a[kOutputsPerThread], w[kOutputsPerThread];
            #pragma unroll
            for (unsigned i = 0; i < kOutputsPerThread; ++i) {
                a[i] = activations[k][lane_y + i * kThreadSide];
                w[i] = weights[k][lane_x + i * kThreadSide];
            }
            #pragma unroll
            for (unsigned i = 0; i < kOutputsPerThread; ++i) {
                #pragma unroll
                for (unsigned j = 0; j < kOutputsPerThread; ++j) {
                    sums[i][j] = fmaf(a[i], w[j], sums[i][j]);
                }
            }
        }
        __syncthreads();
    }

    #pragma unroll
    for (unsigned j = 0; j < kOutputsPerThread; ++j) {
        const size_t col = tile_col + lane_x + j * kThreadSide;
        if (FullTiles || col < M) {
            const float bias = b[col];
            #pragma unroll
            for (unsigned i = 0; i < kOutputsPerThread; ++i) {
                const size_t row = tile_row + lane_y + i * kThreadSide;
                if (FullTiles || row < B) {
                    const float value = sums[i][j] + bias;
                    C[row * M + col] = value < 0.0f ? 0.0f : value;
                }
            }
        }
    }
}

}  // namespace

extern "C" void solution(const float* A, const float* W, const float* b, float* C,
                         size_t B, size_t N, size_t M) {
    if (B == 0 || M == 0) return;
    constexpr unsigned kThreads = kThreadSide * kThreadSide;
    const dim3 grid(static_cast<unsigned>(1 + (M - 1) / kTile),
                    static_cast<unsigned>(1 + (B - 1) / kTile));
    const bool aligned = (reinterpret_cast<uintptr_t>(A) |
                          reinterpret_cast<uintptr_t>(W)) % alignof(float4) == 0;
    if (aligned && B % kTile == 0 && M % kTile == 0 && N % kDepth == 0) {
        gemm_relu<true><<<grid, kThreads>>>(A, W, b, C, B, N, M);
    } else {
        gemm_relu<false><<<grid, kThreads>>>(A, W, b, C, B, N, M);
    }
}
