#include <cuda_runtime.h>
#include <cstddef>
#include <cstdint>

namespace {

constexpr unsigned kThreads = 256;
constexpr unsigned kMaxBlocks = 4096;

__device__ __forceinline__ float hard_sigmoid(float x) {
    if (x <= -3.0f) return 0.0f;
    if (x >= 3.0f) return 1.0f;
    return (x + 3.0f) / 6.0f;
}

__device__ __forceinline__ float4 hard_sigmoid(float4 x) {
    return make_float4(hard_sigmoid(x.x), hard_sigmoid(x.y),
                       hard_sigmoid(x.z), hard_sigmoid(x.w));
}

template <typename Value>
__global__ void activate(const Value* input, Value* output, size_t count) {
    const size_t first = static_cast<size_t>(blockIdx.x) * blockDim.x + threadIdx.x;
    const size_t stride = static_cast<size_t>(gridDim.x) * blockDim.x;
    for (size_t i = first; i < count; i += stride) {
        output[i] = hard_sigmoid(input[i]);
    }
}

unsigned blocks_for(size_t count) {
    const size_t blocks = 1 + (count - 1) / kThreads;
    return static_cast<unsigned>(blocks < kMaxBlocks ? blocks : kMaxBlocks);
}

}  // namespace

extern "C" void solution(const float* input, float* output, size_t n, size_t m) {
    if (n == 0 || m == 0) return;

    const size_t count = n * m;
    const bool aligned = reinterpret_cast<std::uintptr_t>(input) % alignof(float4) == 0 &&
                         reinterpret_cast<std::uintptr_t>(output) % alignof(float4) == 0;
    if (aligned && count % 4 == 0) {
        const size_t vectors = count / 4;
        activate<<<blocks_for(vectors), kThreads>>>(reinterpret_cast<const float4*>(input),
                                                  reinterpret_cast<float4*>(output), vectors);
    } else {
        activate<<<blocks_for(count), kThreads>>>(input, output, count);
    }
}
