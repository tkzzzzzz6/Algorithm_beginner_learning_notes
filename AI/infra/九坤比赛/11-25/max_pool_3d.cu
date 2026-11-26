#include <cuda_runtime.h>
#include <stddef.h>
#include <stdint.h>

namespace {

constexpr int kWarp = 32;
constexpr int kThreads = 256;

struct Shape {
    int h, w, d;
};

__device__ __forceinline__ float neg_inf() {
    return __int_as_float(0xff800000u);
}

__device__ __forceinline__ float pool_max(float a, float b) {
#if __CUDA_ARCH__ >= 800
    float result;
    asm("max.NaN.f32 %0, %1, %2;" : "=f"(result) : "f"(a), "f"(b));
    return result;
#else
    return a > b || isnan(a) ? a : b;
#endif
}

__device__ __forceinline__ float load_x(const float* row, int x, int width) {
    return static_cast<unsigned>(x) < static_cast<unsigned>(width) ? row[x] : neg_inf();
}

template <int K, int S, int Dilation>
__device__ __forceinline__ float pool_x(const float* row, int x, int width, int lane) {
    if constexpr (S == Dilation) {
        const float v = load_x(row, x, width);
        const float halo = lane < K - 1 ? load_x(row, x + kWarp * S, width) : neg_inf();
        float result = v;
        #pragma unroll
        for (int k = 1; k < K; ++k) {
            const int src = lane + k;
            const float within = __shfl_sync(0xffffffffu, v, src & 31);
            const float beyond = __shfl_sync(0xffffffffu, halo, src & 31);
            result = pool_max(result, src < kWarp ? within : beyond);
        }
        return result;
    } else if constexpr (K == 4 && S == 4 && Dilation == 1) {
        if (x >= 0 && x + 3 < width && (reinterpret_cast<uintptr_t>(row + x) & 7u) == 0) {
            const auto* pairs = reinterpret_cast<const float2*>(row + x);
            const float2 lo = pairs[0], hi = pairs[1];
            return pool_max(pool_max(lo.x, lo.y), pool_max(hi.x, hi.y));
        }
    }
    float result = neg_inf();
    #pragma unroll
    for (int k = 0; k < K; ++k) {
        result = pool_max(result, load_x(row, x + k * Dilation, width));
    }
    return result;
}

template <int K, int S, int P, int Dilation>
__global__ void pool_tiled(const float* input, float* output, Shape in, Shape out) {
    constexpr int kTile = 4;
    constexpr int factor = S == Dilation ? S : 1;
    constexpr int step = S / factor;
    constexpr int gap = Dilation / factor;
    constexpr int extent = (kTile - 1) * step + (K - 1) * gap + 1;
    __shared__ float col_max[extent][extent][kWarp];
    __shared__ float row_max[extent][kTile][kWarp];

    const int lane = threadIdx.x % kWarp;
    const int warp = threadIdx.x / kWarp;
    const int ox = blockIdx.x * kWarp + lane;
    const int oy = blockIdx.y * kTile;
    const int oz = blockIdx.z * kTile;

    // Reduce contiguous rows first. When stride equals dilation, the tile visits
    // only the relevant residue class on the other two axes.
    for (int item = warp; item < extent * extent; item += kThreads / kWarp) {
        const int local_z = item / extent;
        const int local_y = item % extent;
        const int z = oz * S - P + local_z * factor;
        const int y = oy * S - P + local_y * factor;
        float value = neg_inf();
        if (static_cast<unsigned>(z) < static_cast<unsigned>(in.h) &&
            static_cast<unsigned>(y) < static_cast<unsigned>(in.w)) {
            const float* row = input + (static_cast<size_t>(z) * in.w + y) * in.d;
            value = pool_x<K, S, Dilation>(row, ox * S - P, in.d, lane);
        }
        col_max[local_z][local_y][lane] = value;
    }
    __syncthreads();

    for (int item = warp; item < extent * kTile; item += kThreads / kWarp) {
        const int local_z = item / kTile;
        const int local_y = item % kTile;
        float value = neg_inf();
        #pragma unroll
        for (int k = 0; k < K; ++k) {
            value = pool_max(value, col_max[local_z][local_y * step + k * gap][lane]);
        }
        row_max[local_z][local_y][lane] = value;
    }
    __syncthreads();

    for (int item = warp; item < kTile * kTile; item += kThreads / kWarp) {
        const int local_z = item / kTile;
        const int local_y = item % kTile;
        if (ox < out.d && oy + local_y < out.w && oz + local_z < out.h) {
            float value = neg_inf();
            #pragma unroll
            for (int k = 0; k < K; ++k) {
                value = pool_max(value, row_max[local_z * step + k * gap][local_y][lane]);
            }
            output[(static_cast<size_t>(oz + local_z) * out.w + oy + local_y) * out.d + ox] = value;
        }
    }
}

__global__ void pool_generic(const float* input, float* output, Shape in, Shape out,
                             int k, int stride, int pad, int dilation, size_t count) {
    for (size_t i = blockIdx.x * blockDim.x + threadIdx.x; i < count;
         i += static_cast<size_t>(gridDim.x) * blockDim.x) {
        const int64_t x0 = static_cast<int64_t>(i % out.d) * stride - pad;
        const int64_t y0 = static_cast<int64_t>(i / out.d % out.w) * stride - pad;
        const int64_t z0 = static_cast<int64_t>(i / out.d / out.w) * stride - pad;
        float value = neg_inf();
        for (int dz = 0; dz < k; ++dz) {
            const int64_t z = z0 + static_cast<int64_t>(dz) * dilation;
            if (z < 0 || z >= in.h) continue;
            for (int dy = 0; dy < k; ++dy) {
                const int64_t y = y0 + static_cast<int64_t>(dy) * dilation;
                if (y < 0 || y >= in.w) continue;
                const float* row = input + (static_cast<size_t>(z) * in.w + y) * in.d;
                for (int dx = 0; dx < k; ++dx) {
                    const int64_t x = x0 + static_cast<int64_t>(dx) * dilation;
                    if (x >= 0 && x < in.d) value = pool_max(value, row[x]);
                }
            }
        }
        output[i] = value;
    }
}

int output_size(int length, int kernel_size, int stride, int padding, int dilation) {
    const int64_t available = length + 2LL * padding
        - (static_cast<int64_t>(kernel_size) - 1) * dilation - 1;
    const int64_t size = available < 0 ? 0 : available / stride + 1;
    return size <= 0x7fffffff ? static_cast<int>(size) : 0;
}

}  // namespace

extern "C" void solution(const float* input, int kernel_size, int stride, int padding,
                         int dilation, float* output, size_t H, size_t W, size_t D) {
    if (!H || !W || !D || H > 0x7fffffff || W > 0x7fffffff || D > 0x7fffffff ||
        kernel_size < 1 || stride < 1 || padding < 0 || dilation < 1) return;
    const Shape in{static_cast<int>(H), static_cast<int>(W), static_cast<int>(D)};
    const Shape out{output_size(in.h, kernel_size, stride, padding, dilation),
                    output_size(in.w, kernel_size, stride, padding, dilation),
                    output_size(in.d, kernel_size, stride, padding, dilation)};
    if (out.h == 0 || out.w == 0 || out.d == 0) return;
    if (out.h <= 65535 * 4 && out.w <= 65535 * 4 && D < (1u << 30)) {
        const dim3 tiles(1 + (out.d - 1) / kWarp, 1 + (out.w - 1) / 4, 1 + (out.h - 1) / 4);
        #define POOL_CASE(K, S, P, DIL) \
            if (kernel_size == (K) && stride == (S) && padding == (P) && dilation == (DIL)) { \
                pool_tiled<K, S, P, DIL><<<tiles, kThreads>>>(input, output, in, out); \
                return; \
            }
        POOL_CASE(2, 2, 0, 2)
        POOL_CASE(3, 2, 1, 1)
        POOL_CASE(4, 4, 2, 1)
        POOL_CASE(3, 3, 1, 3)
        POOL_CASE(5, 2, 2, 2)
        POOL_CASE(7, 3, 3, 1)
        #undef POOL_CASE
    }
    const size_t count = static_cast<size_t>(out.h) * out.w * out.d;
    const size_t requested_blocks = 1 + (count - 1) / kThreads;
    const unsigned blocks = static_cast<unsigned>(requested_blocks < 4096 ? requested_blocks : 4096);
    pool_generic<<<blocks, kThreads>>>(input, output, in, out, kernel_size, stride, padding,
                                      dilation, count);
}
