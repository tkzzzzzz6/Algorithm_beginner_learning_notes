#include <cuda_runtime.h>
#include <cstddef>
#include <cstdint>

namespace {

constexpr unsigned kThreads = 256;
constexpr unsigned kMaxBlocks = 4096;

__device__ __forceinline__ float hinge_loss(float prediction, float target) {
    const float margin = fmaf(-prediction, target, 1.0f);
    return margin < 0.0f ? 0.0f : margin;
}

__device__ __forceinline__ float4 hinge_loss(float4 prediction, float4 target) {
    return make_float4(hinge_loss(prediction.x, target.x),
                       hinge_loss(prediction.y, target.y),
                       hinge_loss(prediction.z, target.z),
                       hinge_loss(prediction.w, target.w));
}

template <typename Value>
__global__ void hinge_elements(const Value* predictions, const Value* targets,
                               Value* output, size_t count) {
    const size_t first = static_cast<size_t>(blockIdx.x) * blockDim.x + threadIdx.x;
    const size_t stride = static_cast<size_t>(gridDim.x) * blockDim.x;
    for (size_t i = first; i < count; i += stride) {
        output[i] = hinge_loss(predictions[i], targets[i]);
    }
}

unsigned blocks_for(size_t count) {
    const size_t blocks = 1 + (count - 1) / kThreads;
    return static_cast<unsigned>(blocks < kMaxBlocks ? blocks : kMaxBlocks);
}

}  // namespace

extern "C" void solution(const float* predictions, const float* targets,
                         float* output, size_t n) {
    if (n == 0) return;

    const bool aligned = reinterpret_cast<std::uintptr_t>(predictions) % alignof(float4) == 0 &&
                         reinterpret_cast<std::uintptr_t>(targets) % alignof(float4) == 0 &&
                         reinterpret_cast<std::uintptr_t>(output) % alignof(float4) == 0;
    if (aligned && n % 4 == 0) {
        const size_t count = n / 4;
        hinge_elements<<<blocks_for(count), kThreads>>>(
            reinterpret_cast<const float4*>(predictions),
            reinterpret_cast<const float4*>(targets), reinterpret_cast<float4*>(output), count);
    } else {
        hinge_elements<<<blocks_for(n), kThreads>>>(predictions, targets, output, n);
    }
}
