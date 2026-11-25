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
__global__ void gemm_swish(const float* input, const float* weights, const float* bias,
                           float scale, float* output,
                           size_t batch_size, size_t in_features, size_t out_features) {
    // Shared tiles transpose the contiguous reduction dimension for reuse.
    __shared__ float input_tile[kDepth][kTile + 1];
    __shared__ float weight_tile[kDepth][kTile + 1];
    const unsigned lane_x = threadIdx.x % kThreadSide;
    const unsigned lane_y = threadIdx.x / kThreadSide;
    const size_t tile_row = static_cast<size_t>(blockIdx.y) * kTile;
    const size_t tile_col = static_cast<size_t>(blockIdx.x) * kTile;
    float sums[kOutputsPerThread][kOutputsPerThread] = {};

    for (size_t k0 = 0; k0 < in_features; k0 += kDepth) {
        load_tile<FullTiles>(input, input_tile, batch_size, in_features, tile_row, k0);
        load_tile<FullTiles>(weights, weight_tile, out_features, in_features, tile_col, k0);
        __syncthreads();

        #pragma unroll
        for (unsigned k = 0; k < kDepth; ++k) {
            float x[kOutputsPerThread], w[kOutputsPerThread];
            #pragma unroll
            for (unsigned i = 0; i < kOutputsPerThread; ++i) {
                x[i] = input_tile[k][lane_y + i * kThreadSide];
                w[i] = weight_tile[k][lane_x + i * kThreadSide];
            }
            #pragma unroll
            for (unsigned i = 0; i < kOutputsPerThread; ++i) {
                #pragma unroll
                for (unsigned j = 0; j < kOutputsPerThread; ++j) {
                    sums[i][j] = fmaf(x[i], w[j], sums[i][j]);
                }
            }
        }
        __syncthreads();
    }

    #pragma unroll
    for (unsigned j = 0; j < kOutputsPerThread; ++j) {
        const size_t col = tile_col + lane_x + j * kThreadSide;
        if (FullTiles || col < out_features) {
            const float shift = bias[col];
            #pragma unroll
            for (unsigned i = 0; i < kOutputsPerThread; ++i) {
                const size_t row = tile_row + lane_y + i * kThreadSide;
                if (FullTiles || row < batch_size) {
                    const float z = sums[i][j] + shift;
                    output[row * out_features + col] = scale * (z / (1.0f + expf(-z)));
                }
            }
        }
    }
}

}  // namespace

extern "C" void solution(const float* input_matrix, const float* weight_matrix,
                         const float* bias, const float scaling_factor, float* output,
                         size_t batch_size, size_t in_features, size_t out_features) {
    if (batch_size == 0 || out_features == 0) return;

    constexpr unsigned kThreads = kThreadSide * kThreadSide;
    const dim3 grid(static_cast<unsigned>(1 + (out_features - 1) / kTile),
                    static_cast<unsigned>(1 + (batch_size - 1) / kTile));
    const bool aligned = (reinterpret_cast<uintptr_t>(input_matrix) |
                          reinterpret_cast<uintptr_t>(weight_matrix)) % alignof(float4) == 0;
    if (aligned && batch_size % kTile == 0 && out_features % kTile == 0 &&
        in_features % kDepth == 0) {
        gemm_swish<true><<<grid, kThreads>>>(input_matrix, weight_matrix, bias, scaling_factor,
                                            output, batch_size, in_features, out_features);
    } else {
        gemm_swish<false><<<grid, kThreads>>>(input_matrix, weight_matrix, bias, scaling_factor,
                                             output, batch_size, in_features, out_features);
    }
}
