#include <cuda_runtime.h>
#include <stddef.h>
#include <stdint.h>

namespace {

constexpr unsigned kThreads = 256;
constexpr unsigned kMaxBlocks = 2048;

__device__ __forceinline__ float binarize(float pixel, float threshold) {
    return pixel > threshold ? 255.0f : 0.0f;
}

__global__ void threshold_vectors(const float4* input, float4* output, size_t count,
                                  float threshold) {
    const size_t step = static_cast<size_t>(gridDim.x) * blockDim.x;
    for (size_t i = static_cast<size_t>(blockIdx.x) * blockDim.x + threadIdx.x;
         i < count; i += step) {
        const float4 x = input[i];
        output[i] = make_float4(binarize(x.x, threshold), binarize(x.y, threshold),
                                binarize(x.z, threshold), binarize(x.w, threshold));
    }
}

__global__ void threshold_scalars(const float* input, float* output, size_t count,
                                  float threshold) {
    const size_t step = static_cast<size_t>(gridDim.x) * blockDim.x;
    for (size_t i = static_cast<size_t>(blockIdx.x) * blockDim.x + threadIdx.x;
         i < count; i += step) {
        output[i] = binarize(input[i], threshold);
    }
}

unsigned blocks_for(size_t count) {
    const size_t needed = 1 + (count - 1) / kThreads;
    return static_cast<unsigned>(needed < kMaxBlocks ? needed : kMaxBlocks);
}

}  // namespace

extern "C" void solution(const float* input_image, float threshold_value, float* output_image,
                         size_t height, size_t width) {
    if (height == 0 || width == 0 || height > SIZE_MAX / width) return;
    const size_t count = height * width;
    const uintptr_t addresses = reinterpret_cast<uintptr_t>(input_image) |
                                reinterpret_cast<uintptr_t>(output_image);
    if (count % 4 == 0 && addresses % alignof(float4) == 0) {
        const size_t vectors = count / 4;
        threshold_vectors<<<blocks_for(vectors), kThreads>>>(reinterpret_cast<const float4*>(input_image),
            reinterpret_cast<float4*>(output_image), vectors, threshold_value);
    } else {
        threshold_scalars<<<blocks_for(count), kThreads>>>(input_image, output_image, count, threshold_value);
    }
}
