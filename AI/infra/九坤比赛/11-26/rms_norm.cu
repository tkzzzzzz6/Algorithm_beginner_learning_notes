#include <cuda_runtime.h>
#include <stddef.h>
#include <stdint.h>

namespace {

constexpr unsigned kThreads = 256;
constexpr unsigned kWarpSize = 32;
constexpr unsigned kWarps = kThreads / kWarpSize;
constexpr float kEpsilon = 1e-5f;

__device__ __forceinline__ float warp_sum(float value) {
    for (unsigned offset = kWarpSize / 2; offset != 0; offset /= 2) {
        value += __shfl_down_sync(0xffffffffu, value, offset);
    }
    return value;
}

__device__ __forceinline__ float inverse_rms(float squares, float inv_features) {
    __shared__ float warp_totals[kWarps];
    __shared__ float inverse;
    const unsigned lane = threadIdx.x % kWarpSize;
    const unsigned warp = threadIdx.x / kWarpSize;
    const float sum = warp_sum(squares);
    if (lane == 0) warp_totals[warp] = sum;
    __syncthreads();
    if (warp == 0) {
        const float total = warp_sum(lane < kWarps ? warp_totals[lane] : 0.0f);
        if (lane == 0) inverse = rsqrtf(fmaf(total, inv_features, kEpsilon));
    }
    __syncthreads();
    return inverse;
}

template <unsigned Items>
__global__ void rms_vectorized(const float4* input, float4* output, size_t rows) {
    constexpr unsigned vectors = Items * kThreads;
    constexpr float inv_features = 1.0f / (4 * vectors);
    for (size_t row = blockIdx.x; row < rows; row += gridDim.x) {
        const size_t base = row * vectors + threadIdx.x;
        float4 saved[Items];
        float sum = 0.0f;
        #pragma unroll
        for (unsigned i = 0; i < Items; ++i) {
            const float4 x = input[base + i * kThreads];
            saved[i] = x;
            sum = fmaf(x.x, x.x, sum);
            sum = fmaf(x.y, x.y, sum);
            sum = fmaf(x.z, x.z, sum);
            sum = fmaf(x.w, x.w, sum);
        }
        const float scale = inverse_rms(sum, inv_features);
        #pragma unroll
        for (unsigned i = 0; i < Items; ++i) {
            const float4 x = saved[i];
            output[base + i * kThreads] = make_float4(x.x * scale, x.y * scale, x.z * scale, x.w * scale);
        }
    }
}

__global__ void rms_generic(const float* input, float* output, size_t rows, size_t features) {
    const float inv_features = 1.0f / static_cast<float>(features);
    for (size_t row = blockIdx.x; row < rows; row += gridDim.x) {
        const size_t begin = row * features;
        float squares = 0.0f;
        for (size_t j = threadIdx.x; j < features; j += kThreads) {
            const float x = input[begin + j];
            squares = fmaf(x, x, squares);
        }
        const float scale = inverse_rms(squares, inv_features);
        for (size_t j = threadIdx.x; j < features; j += kThreads) {
            output[begin + j] = input[begin + j] * scale;
        }
    }
}

}  // namespace

extern "C" void solution(const float* X, float* Y, size_t B, size_t N) {
    if (B == 0 || N == 0) return;
    const unsigned blocks = static_cast<unsigned>(B < 65535 ? B : 65535);
    const uintptr_t addresses = reinterpret_cast<uintptr_t>(X) | reinterpret_cast<uintptr_t>(Y);
    if (addresses % alignof(float4) == 0) {
        const auto* input = reinterpret_cast<const float4*>(X);
        auto* output = reinterpret_cast<float4*>(Y);
        switch (N) {
            case 1024: rms_vectorized<1><<<blocks, kThreads>>>(input, output, B); return;
            case 4096: rms_vectorized<4><<<blocks, kThreads>>>(input, output, B); return;
            case 8192: rms_vectorized<8><<<blocks, kThreads>>>(input, output, B); return;
            case 16384: rms_vectorized<16><<<blocks, kThreads>>>(input, output, B); return;
        }
    }
    rms_generic<<<blocks, kThreads>>>(X, Y, B, N);
}
