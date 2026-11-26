#include <cuda_runtime.h>
#include <stddef.h>
#include <stdint.h>

namespace {

constexpr unsigned kSide = 16;
constexpr unsigned kPerThread = 4;
constexpr unsigned kTile = kSide * kPerThread;
constexpr unsigned kDepth = 16;
constexpr unsigned kThreads = kSide * kSide;

template <bool FullTiles>
__global__ void multiply(const float* left, const float* right, float* result, size_t size) {
    __shared__ float left_tile[kDepth][kTile + 1];
    __shared__ float right_tile[kDepth][kTile];
    const unsigned lane_row = threadIdx.x / kSide;
    const unsigned lane_col = threadIdx.x % kSide;
    const size_t row0 = static_cast<size_t>(blockIdx.y) * kTile;
    const size_t col0 = static_cast<size_t>(blockIdx.x) * kTile;
    const unsigned load_left_row = threadIdx.x / (kDepth / 4);
    const unsigned load_left_k = 4 * (threadIdx.x % (kDepth / 4));
    const unsigned load_right_k = threadIdx.x / (kTile / 4);
    const unsigned load_right_col = 4 * (threadIdx.x % (kTile / 4));
    const size_t row = row0 + load_left_row;
    const size_t col = col0 + load_right_col;
    float sums[kPerThread][kPerThread] = {};

    for (size_t k0 = 0; k0 < size; k0 += kDepth) {
        if (FullTiles) {
            const float4 a = *reinterpret_cast<const float4*>(left + row * size + k0 + load_left_k);
            const float4 b = *reinterpret_cast<const float4*>(right + (k0 + load_right_k) * size + col);
            left_tile[load_left_k][load_left_row] = a.x;
            left_tile[load_left_k + 1][load_left_row] = a.y;
            left_tile[load_left_k + 2][load_left_row] = a.z;
            left_tile[load_left_k + 3][load_left_row] = a.w;
            right_tile[load_right_k][load_right_col] = b.x;
            right_tile[load_right_k][load_right_col + 1] = b.y;
            right_tile[load_right_k][load_right_col + 2] = b.z;
            right_tile[load_right_k][load_right_col + 3] = b.w;
        } else {
            #pragma unroll
            for (unsigned j = 0; j < 4; ++j) {
                const size_t ak = k0 + load_left_k + j;
                const size_t bk = k0 + load_right_k;
                left_tile[load_left_k + j][load_left_row] =
                    row < size && ak < size ? left[row * size + ak] : 0.0f;
                right_tile[load_right_k][load_right_col + j] =
                    bk < size && col + j < size ? right[bk * size + col + j] : 0.0f;
            }
        }
        __syncthreads();

        #pragma unroll
        for (unsigned k = 0; k < kDepth; ++k) {
            float a[kPerThread], b[kPerThread];
            #pragma unroll
            for (unsigned j = 0; j < kPerThread; ++j) {
                a[j] = left_tile[k][lane_row + j * kSide];
                b[j] = right_tile[k][lane_col + j * kSide];
            }
            #pragma unroll
            for (unsigned i = 0; i < kPerThread; ++i) {
                #pragma unroll
                for (unsigned j = 0; j < kPerThread; ++j) {
                    sums[i][j] = fmaf(a[i], b[j], sums[i][j]);
                }
            }
        }
        __syncthreads();
    }

    #pragma unroll
    for (unsigned i = 0; i < kPerThread; ++i) {
        const size_t dst_row = row0 + lane_row + i * kSide;
        #pragma unroll
        for (unsigned j = 0; j < kPerThread; ++j) {
            const size_t dst_col = col0 + lane_col + j * kSide;
            if (FullTiles || (dst_row < size && dst_col < size)) {
                result[dst_row * size + dst_col] = sums[i][j];
            }
        }
    }
}

void launch_product(const float* left, const float* right, float* result, size_t size) {
    const unsigned tiles = static_cast<unsigned>(1 + (size - 1) / kTile);
    const dim3 grid(tiles, tiles);
    const auto inputs = reinterpret_cast<uintptr_t>(left) | reinterpret_cast<uintptr_t>(right);
    if (size % kTile == 0 && inputs % alignof(float4) == 0) {
        multiply<true><<<grid, kThreads>>>(left, right, result, size);
    } else {
        multiply<false><<<grid, kThreads>>>(left, right, result, size);
    }
}

__global__ void identity(float* output, size_t size, size_t count) {
    const size_t idx = static_cast<size_t>(blockIdx.x) * blockDim.x + threadIdx.x;
    if (idx < count) output[idx] = idx % (size + 1) == 0 ? 1.0f : 0.0f;
}

}  // namespace

extern "C" void solution(const float* input_matrix, const size_t n, float* output_matrix,
                         size_t size) {
    if (size == 0) return;
    const size_t count = size * size;
    const size_t bytes = count * sizeof(float);
    if (n == 0) {
        identity<<<1 + (count - 1) / kThreads, kThreads>>>(output_matrix, size, count);
        return;
    }
    if (n == 1) {
        if (output_matrix != input_matrix) {
            cudaMemcpyAsync(output_matrix, input_matrix, bytes, cudaMemcpyDeviceToDevice);
        }
        return;
    }
    const bool separate_output = output_matrix != input_matrix;
    if (n == 2 && separate_output) {
        launch_product(input_matrix, input_matrix, output_matrix, size);
        return;
    }

    float* scratch = nullptr;
    const bool async_alloc = cudaMallocAsync(&scratch, 2 * bytes, 0) == cudaSuccess;
    if (!async_alloc) {
        cudaGetLastError();
        if (cudaMalloc(&scratch, 2 * bytes) != cudaSuccess) return;
    }
    float* alternate = scratch + count;

    size_t bit = 1;
    while (bit <= (n >> 1)) bit <<= 1;
    const float* current = input_matrix;
    // The leading bit is already represented by A. Each later bit squares the
    // accumulated power, and a one-bit contributes one extra factor of A.
    for (bit >>= 1; bit != 0; bit >>= 1) {
        const bool odd = (n & bit) != 0;
        float* next = current == scratch ? alternate : scratch;
        if (bit == 1 && !odd && separate_output) next = output_matrix;
        launch_product(current, current, next, size);
        current = next;
        if (odd) {
            next = current == scratch ? alternate : scratch;
            if (bit == 1 && separate_output) next = output_matrix;
            launch_product(current, input_matrix, next, size);
            current = next;
        }
    }
    if (current != output_matrix) {
        cudaMemcpyAsync(output_matrix, current, bytes, cudaMemcpyDeviceToDevice);
    }
    if (async_alloc) {
        cudaFreeAsync(scratch, 0);
    } else {
        cudaFree(scratch);
    }
}
