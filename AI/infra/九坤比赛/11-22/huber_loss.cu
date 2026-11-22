#include <cuda_runtime.h>
#include <cstddef>
#include <cstdint>

namespace {

constexpr unsigned kThreads = 256;
constexpr unsigned kMaxBlocks = 4096;

__device__ __forceinline__ float huber(float prediction, float target) {
    const float magnitude = fabsf(prediction - target);
    return magnitude < 1.0f ? (0.5f * magnitude) * magnitude : magnitude - 0.5f;
}

__device__ __forceinline__ float4 huber(float4 prediction, float4 target) {
    return make_float4(huber(prediction.x, target.x), huber(prediction.y, target.y),
                       huber(prediction.z, target.z), huber(prediction.w, target.w));
}

template <typename Value>
__global__ void huber_elements(const Value* predictions, const Value* targets,
                               Value* output, size_t count) {
    const size_t start = static_cast<size_t>(blockIdx.x) * blockDim.x + threadIdx.x;
    const size_t stride = static_cast<size_t>(gridDim.x) * blockDim.x;
    for (size_t i = start; i < count; i += stride) {
        output[i] = huber(predictions[i], targets[i]);
    }
}

unsigned blocks_for(size_t count) {
    const size_t blocks = 1 + (count - 1) / kThreads;
    return blocks < kMaxBlocks ? static_cast<unsigned>(blocks) : kMaxBlocks;
}

}  // namespace

extern "C" void solution(const float* predictions, const float* targets, float* output,
                         size_t n) {
    if (n == 0) return;

    const auto addresses = reinterpret_cast<std::uintptr_t>(predictions) |
                           reinterpret_cast<std::uintptr_t>(targets) |
                           reinterpret_cast<std::uintptr_t>(output);
    if (n % 4 == 0 && addresses % alignof(float4) == 0) {
        const size_t vectors = n / 4;
        huber_elements<<<blocks_for(vectors), kThreads>>>(
            reinterpret_cast<const float4*>(predictions),
            reinterpret_cast<const float4*>(targets), reinterpret_cast<float4*>(output), vectors);
    } else {
        huber_elements<<<blocks_for(n), kThreads>>>(predictions, targets, output, n);
    }
}
