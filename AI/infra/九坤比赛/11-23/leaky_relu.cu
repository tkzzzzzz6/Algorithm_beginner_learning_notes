#include <cuda_runtime.h>
#include <stddef.h>
#include <stdint.h>

namespace {

constexpr unsigned kThreads = 256;
constexpr unsigned kMaxBlocks = 4096;

__device__ __forceinline__ float leaky_relu(float x, float alpha) {
    return x > 0.0f ? x : alpha * x;
}

__device__ __forceinline__ float4 leaky_relu(float4 x, float alpha) {
    return make_float4(leaky_relu(x.x, alpha), leaky_relu(x.y, alpha),
                       leaky_relu(x.z, alpha), leaky_relu(x.w, alpha));
}

template <typename Element>
__global__ void activate_elements(const Element* input, Element* output,
                                  size_t count, float alpha) {
    const size_t first = static_cast<size_t>(blockIdx.x) * blockDim.x + threadIdx.x;
    const size_t stride = static_cast<size_t>(gridDim.x) * blockDim.x;
    for (size_t i = first; i < count; i += stride) {
        output[i] = leaky_relu(input[i], alpha);
    }
}

unsigned blocks_for(size_t count) {
    const size_t blocks = 1 + (count - 1) / kThreads;
    return static_cast<unsigned>(blocks < kMaxBlocks ? blocks : kMaxBlocks);
}

}  // namespace

extern "C" void solution(const float* input, float alpha, float* output, size_t n, size_t m) {
    if (n == 0 || m == 0) return;

    const size_t count = n * m;
    const bool aligned = (reinterpret_cast<uintptr_t>(input) |
                          reinterpret_cast<uintptr_t>(output)) % alignof(float4) == 0;
    if (aligned && count % 4 == 0) {
        const size_t vectors = count / 4;
        activate_elements<<<blocks_for(vectors), kThreads>>>(
            reinterpret_cast<const float4*>(input), reinterpret_cast<float4*>(output), vectors, alpha);
    } else {
        activate_elements<<<blocks_for(count), kThreads>>>(input, output, count, alpha);
    }
}
