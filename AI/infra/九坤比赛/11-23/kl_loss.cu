#include <cuda_runtime.h>
#include <cstddef>
#include <cstdint>

namespace {

constexpr unsigned kThreads = 256;
constexpr unsigned kMaxBlocks = 4096;
constexpr float kEpsilon = 1e-10f;

__device__ __forceinline__ float kl_term(float prediction, float target) {
    if (!(target > 0.0f)) return 0.0f;
    const float p = fmaxf(target, kEpsilon);
    const float q = fmaxf(prediction, kEpsilon);
    return p * (logf(p) - logf(q));
}

__device__ __forceinline__ float4 kl_term(float4 q, float4 p) {
    return make_float4(kl_term(q.x, p.x), kl_term(q.y, p.y),
                       kl_term(q.z, p.z), kl_term(q.w, p.w));
}

template <typename Value>
__global__ void compute_kl(const Value* predictions, const Value* targets,
                           Value* output, size_t count) {
    const size_t first = static_cast<size_t>(blockIdx.x) * blockDim.x + threadIdx.x;
    const size_t stride = static_cast<size_t>(gridDim.x) * blockDim.x;
    for (size_t i = first; i < count; i += stride) {
        output[i] = kl_term(predictions[i], targets[i]);
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

    const auto addresses = reinterpret_cast<std::uintptr_t>(predictions) |
                           reinterpret_cast<std::uintptr_t>(targets) |
                           reinterpret_cast<std::uintptr_t>(output);
    if (addresses % alignof(float4) == 0 && n % 4 == 0) {
        const size_t vectors = n / 4;
        compute_kl<<<blocks_for(vectors), kThreads>>>(
            reinterpret_cast<const float4*>(predictions), reinterpret_cast<const float4*>(targets),
            reinterpret_cast<float4*>(output), vectors);
    } else {
        compute_kl<<<blocks_for(n), kThreads>>>(predictions, targets, output, n);
    }
}
