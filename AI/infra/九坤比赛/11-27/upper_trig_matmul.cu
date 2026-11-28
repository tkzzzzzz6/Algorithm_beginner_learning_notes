#include <cuda_runtime.h>
#include <stddef.h>
#include <stdint.h>

namespace {

constexpr unsigned kSide = 16;
constexpr unsigned kPerThread = 4;
constexpr unsigned kTile = kSide * kPerThread;
constexpr unsigned kDepth = 16;
constexpr unsigned kThreads = kSide * kSide;

template <bool Aligned>
__device__ __forceinline__ void load_tiles(
    const float* a, const float* b, size_t n, size_t row0, size_t col0,
    size_t k0, float (&a_tile)[kDepth][kTile + 1],
    float (&b_tile)[kDepth][kTile]) {
    const unsigned a_row = threadIdx.x / (kDepth / kPerThread);
    const unsigned a_k = kPerThread * (threadIdx.x % (kDepth / kPerThread));
    const unsigned b_k = threadIdx.x / (kTile / kPerThread);
    const unsigned b_col = kPerThread * (threadIdx.x % (kTile / kPerThread));
    const size_t row = row0 + a_row;
    const size_t col = col0 + b_col;
    const size_t ak = k0 + a_k;
    const size_t bk = k0 + b_k;

    // Aligned groups that stay above the diagonal can be loaded together.
    if (Aligned && row <= ak) {
        const float4 values = *reinterpret_cast<const float4*>(a + row * n + ak);
        a_tile[a_k][a_row] = values.x;
        a_tile[a_k + 1][a_row] = values.y;
        a_tile[a_k + 2][a_row] = values.z;
        a_tile[a_k + 3][a_row] = values.w;
    } else {
        #pragma unroll
        for (unsigned i = 0; i < kPerThread; ++i) {
            const size_t k = ak + i;
            a_tile[a_k + i][a_row] =
                row < n && k < n && row <= k ? a[row * n + k] : 0.0f;
        }
    }

    if (Aligned && bk <= col) {
        *reinterpret_cast<float4*>(b_tile[b_k] + b_col) =
            *reinterpret_cast<const float4*>(b + bk * n + col);
    } else {
        #pragma unroll
        for (unsigned i = 0; i < kPerThread; ++i) {
            const size_t j = col + i;
            b_tile[b_k][b_col + i] =
                bk < n && j < n && bk <= j ? b[bk * n + j] : 0.0f;
        }
    }
}

template <bool Aligned>
__global__ void upper_triangular_product(const float* a, const float* b, float* c, size_t n) {
    __shared__ float a_tile[kDepth][kTile + 1];
    __shared__ __align__(16) float b_tile[kDepth][kTile];
    const unsigned lane_row = threadIdx.x / kSide;
    const unsigned lane_col = threadIdx.x % kSide;
    const size_t row0 = static_cast<size_t>(blockIdx.y) * kTile;
    const size_t col0 = static_cast<size_t>(blockIdx.x) * kTile;
    const size_t col_end = col0 + kTile < n ? col0 + kTile : n;
    float sums[kPerThread][kPerThread] = {};

    // For row <= column, a product can contribute only when row <= k <= column.
    for (size_t k0 = row0; k0 < col_end; k0 += kDepth) {
        load_tiles<Aligned>(a, b, n, row0, col0, k0, a_tile, b_tile);
        __syncthreads();

        #pragma unroll
        for (unsigned k = 0; k < kDepth; ++k) {
            float left[kPerThread], right[kPerThread];
            #pragma unroll
            for (unsigned i = 0; i < kPerThread; ++i) {
                left[i] = a_tile[k][lane_row + i * kSide];
                right[i] = b_tile[k][lane_col + i * kSide];
            }
            #pragma unroll
            for (unsigned i = 0; i < kPerThread; ++i) {
                #pragma unroll
                for (unsigned j = 0; j < kPerThread; ++j) {
                    sums[i][j] = fmaf(left[i], right[j], sums[i][j]);
                }
            }
        }
        __syncthreads();
    }

    #pragma unroll
    for (unsigned i = 0; i < kPerThread; ++i) {
        const size_t row = row0 + lane_row + i * kSide;
        #pragma unroll
        for (unsigned j = 0; j < kPerThread; ++j) {
            const size_t col = col0 + lane_col + j * kSide;
            if (Aligned || (row < n && col < n)) {
                c[row * n + col] = row <= col ? sums[i][j] : 0.0f;
            }
        }
    }
}

}  // namespace

extern "C" void solution(const float* input_a, const float* input_b, float* output_c, size_t n) {
    if (n == 0) return;
    const auto tiles = static_cast<unsigned>(1 + (n - 1) / kTile);
    const dim3 grid(tiles, tiles);
    const bool aligned = (reinterpret_cast<uintptr_t>(input_a) |
                          reinterpret_cast<uintptr_t>(input_b)) % alignof(float4) == 0;
    if (aligned && n % kTile == 0) {
        upper_triangular_product<true><<<grid, kThreads>>>(input_a, input_b, output_c, n);
    } else {
        upper_triangular_product<false><<<grid, kThreads>>>(input_a, input_b, output_c, n);
    }
}
