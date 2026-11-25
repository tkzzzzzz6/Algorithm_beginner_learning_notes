#include <cuda_runtime.h>
#include <cstddef>
#include <cstdint>

namespace {

constexpr unsigned kThreads = 256;
constexpr unsigned kWarpSize = 32;
constexpr unsigned kWarps = kThreads / kWarpSize;

template <bool Max>
__device__ __forceinline__ float warp_reduce(float value) {
    #pragma unroll
    for (unsigned offset = kWarpSize / 2; offset > 0; offset /= 2) {
        const float other = __shfl_down_sync(0xffffffffu, value, offset);
        value = Max ? fmaxf(value, other) : value + other;
    }
    return value;
}

template <bool Max>
__device__ __forceinline__ float block_reduce(float value, float* scratch) {
    const unsigned lane = threadIdx.x % kWarpSize;
    const unsigned warp = threadIdx.x / kWarpSize;
    value = warp_reduce<Max>(value);
    if (lane == 0) scratch[warp] = value;
    __syncthreads();

    if (warp == 0) {
        const float identity = Max ? -__int_as_float(0x7f800000) : 0.0f;
        const float partial = lane < kWarps ? scratch[lane] : identity;
        value = warp_reduce<Max>(partial);
        if (lane == 0) scratch[0] = value;
    }
    __syncthreads();
    return scratch[0];
}

template <unsigned Items>
__global__ void log_softmax_vector(const float4* input, float4* output) {
    __shared__ float max_scratch[kWarps], sum_scratch[kWarps];
    const size_t start = static_cast<size_t>(blockIdx.x) * (kThreads * Items) + threadIdx.x;
    float4 values[Items];
    float maximum = -__int_as_float(0x7f800000);
    #pragma unroll
    for (unsigned item = 0; item < Items; ++item) {
        const float4 value = input[start + item * kThreads];
        values[item] = value;
        maximum = fmaxf(maximum, fmaxf(fmaxf(value.x, value.y), fmaxf(value.z, value.w)));
    }
    maximum = block_reduce<true>(maximum, max_scratch);

    float sum = 0.0f;
    #pragma unroll
    for (unsigned item = 0; item < Items; ++item) {
        float4& value = values[item];
        value.x -= maximum;
        value.y -= maximum;
        value.z -= maximum;
        value.w -= maximum;
        sum += (__expf(value.x) + __expf(value.y)) + (__expf(value.z) + __expf(value.w));
    }
    const float log_sum = logf(block_reduce<false>(sum, sum_scratch));

    #pragma unroll
    for (unsigned item = 0; item < Items; ++item) {
        const float4 value = values[item];
        output[start + item * kThreads] = make_float4(value.x - log_sum, value.y - log_sum,
                                                      value.z - log_sum, value.w - log_sum);
    }
}

__global__ void log_softmax_scalar(const float* input, float* output, size_t cols) {
    __shared__ float max_scratch[kWarps], sum_scratch[kWarps];
    const size_t start = static_cast<size_t>(blockIdx.x) * cols;
    float maximum = -__int_as_float(0x7f800000);
    for (size_t col = threadIdx.x; col < cols; col += kThreads) {
        maximum = fmaxf(maximum, input[start + col]);
    }
    maximum = block_reduce<true>(maximum, max_scratch);

    float sum = 0.0f;
    for (size_t col = threadIdx.x; col < cols; col += kThreads) {
        sum += __expf(input[start + col] - maximum);
    }
    const float log_sum = logf(block_reduce<false>(sum, sum_scratch));

    for (size_t col = threadIdx.x; col < cols; col += kThreads) {
        output[start + col] = (input[start + col] - maximum) - log_sum;
    }
}

}  // namespace

extern "C" void solution(const float* input, float* output, size_t M, size_t N) {
    if (M == 0 || N == 0) return;

    const bool aligned = (reinterpret_cast<std::uintptr_t>(input) |
                          reinterpret_cast<std::uintptr_t>(output)) % alignof(float4) == 0;
    if (aligned) {
        const auto* in = reinterpret_cast<const float4*>(input);
        auto* out = reinterpret_cast<float4*>(output);
        switch (N) {
            case 4096: log_softmax_vector<4><<<M, kThreads>>>(in, out); return;
            case 7168: log_softmax_vector<7><<<M, kThreads>>>(in, out); return;
            case 8192: log_softmax_vector<8><<<M, kThreads>>>(in, out); return;
        }
    }
    log_softmax_scalar<<<M, kThreads>>>(input, output, N);
}
