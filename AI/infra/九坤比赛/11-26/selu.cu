#include <cuda_runtime.h>
#include <stddef.h>
#include <stdint.h>

namespace {

constexpr unsigned kThreads = 256;
constexpr unsigned kMaxBlocks = 2048;
constexpr float kScale = 1.0507009873554805f;
constexpr float kAlpha = 1.6732632423543772f;

__device__ __forceinline__ float activate(float x) {
    return x > 0.0f ? kScale * x : (kScale * kAlpha) * expm1f(x);
}

__global__ void selu_vectors(const float4* input, float4* output, size_t count) {
    const size_t step = static_cast<size_t>(gridDim.x) * blockDim.x;
    for (size_t i = static_cast<size_t>(blockIdx.x) * blockDim.x + threadIdx.x;
         i < count; i += step) {
        const float4 x = input[i];
        output[i] = make_float4(activate(x.x), activate(x.y), activate(x.z), activate(x.w));
    }
}

__global__ void selu_scalars(const float* input, float* output, size_t count) {
    const size_t step = static_cast<size_t>(gridDim.x) * blockDim.x;
    for (size_t i = static_cast<size_t>(blockIdx.x) * blockDim.x + threadIdx.x;
         i < count; i += step) {
        output[i] = activate(input[i]);
    }
}

unsigned blocks_for(size_t count) {
    const size_t needed = 1 + (count - 1) / kThreads;
    return static_cast<unsigned>(needed < kMaxBlocks ? needed : kMaxBlocks);
}

}  // namespace

extern "C" void solution(const float* input, float* output, size_t n, size_t m) {
    if (n == 0 || m == 0 || n > SIZE_MAX / m) return;
    const size_t count = n * m;
    const uintptr_t addresses = reinterpret_cast<uintptr_t>(input) |
                                reinterpret_cast<uintptr_t>(output);
    if (count % 4 == 0 && addresses % alignof(float4) == 0) {
        const size_t vectors = count / 4;
        selu_vectors<<<blocks_for(vectors), kThreads>>>(
            reinterpret_cast<const float4*>(input), reinterpret_cast<float4*>(output), vectors);
    } else {
        selu_scalars<<<blocks_for(count), kThreads>>>(input, output, count);
    }
}
