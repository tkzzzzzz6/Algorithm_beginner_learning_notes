#include <cuda_runtime.h>
#include <cstddef>
#include <cstdint>

namespace {

constexpr unsigned kThreads = 256;
constexpr unsigned kMaxBlocks = 4096;

__device__ __forceinline__ float activate(float x, float alpha) {
    return x > 0.0f ? x : alpha * expm1f(x);
}

__device__ __forceinline__ float4 activate(float4 x, float alpha) {
    return make_float4(activate(x.x, alpha), activate(x.y, alpha),
                       activate(x.z, alpha), activate(x.w, alpha));
}

template <class Value>
__global__ void activate_elements(const Value* input, Value* output,
                                  size_t count, float alpha) {
    const size_t start = static_cast<size_t>(blockIdx.x) * blockDim.x + threadIdx.x;
    const size_t stride = static_cast<size_t>(gridDim.x) * blockDim.x;
    for (size_t index = start; index < count; index += stride) {
        output[index] = activate(input[index], alpha);
    }
}

unsigned blocks_for(size_t count) {
    const size_t blocks = 1 + (count - 1) / kThreads;
    return blocks < kMaxBlocks ? static_cast<unsigned>(blocks) : kMaxBlocks;
}

}  // namespace

extern "C" void solution(const float* input, float* output, size_t n,
                         size_t m, float alpha) {
    if (n == 0 || m == 0) return;

    const size_t count = n * m;
    const bool aligned =
        (reinterpret_cast<std::uintptr_t>(input) |
         reinterpret_cast<std::uintptr_t>(output)) % alignof(float4) == 0;
    if (aligned && count % 4 == 0) {
        const size_t vectors = count / 4;
        activate_elements<<<blocks_for(vectors), kThreads>>>(
            reinterpret_cast<const float4*>(input),
            reinterpret_cast<float4*>(output), vectors, alpha);
    } else {
        activate_elements<<<blocks_for(count), kThreads>>>(input, output, count, alpha);
    }
}
