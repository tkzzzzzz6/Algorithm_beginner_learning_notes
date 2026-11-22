#include <cuda_runtime.h>
#include <stddef.h>
#include <stdint.h>

namespace {

constexpr unsigned kThreads = 256;
constexpr unsigned kWarpSize = 32;
constexpr unsigned kMaxBlocks = 1024;

__device__ unsigned warp_max(unsigned value) {
#if defined(__CUDA_ARCH__) && __CUDA_ARCH__ >= 800
    return __reduce_max_sync(0xffffffffu, value);
#else
    for (unsigned offset = kWarpSize / 2; offset > 0; offset /= 2) {
        const unsigned other = __shfl_down_sync(0xffffffffu, value, offset);
        if (other > value) value = other;
    }
    return value;
#endif
}

__device__ unsigned block_max(unsigned value) {
    __shared__ unsigned warp_peaks[kThreads / kWarpSize];
    value = warp_max(value);
    if (threadIdx.x % kWarpSize == 0) warp_peaks[threadIdx.x / kWarpSize] = value;
    __syncthreads();

    if (threadIdx.x < kWarpSize) {
        const unsigned peak = threadIdx.x < kThreads / kWarpSize
            ? warp_peaks[threadIdx.x] : 0;
        return warp_max(peak);
    }
    return 0;
}

template <typename Index>
__global__ void compute_magnitudes(const float* image, float* output,
                                   unsigned* peaks, size_t count, Index width) {
    const size_t step = static_cast<size_t>(gridDim.x) * blockDim.x;
    unsigned peak = 0;
    for (size_t i = static_cast<size_t>(blockIdx.x) * blockDim.x + threadIdx.x;
         i < count; i += step) {
        const Index column = static_cast<Index>(i) % width;
        float magnitude = 0.0f;
        if (i >= width && i < count - width && column != 0 && column + 1 < width) {
            const float dx = (image[i + 1] - image[i - 1]) * 0.5f;
            const float dy = (image[i + width] - image[i - width]) * 0.5f;
            magnitude = sqrtf(dx * dx + dy * dy);
        }
        output[i] = magnitude;

        // Nonnegative floats have the same ordering as their unsigned bit patterns.
        // A NaN bit pattern wins the reduction and disables normalization.
        const unsigned bits = __float_as_uint(magnitude);
        if (bits > peak) peak = bits;
    }
    const unsigned maximum = block_max(peak);
    if (threadIdx.x == 0) peaks[blockIdx.x] = maximum;
}

__global__ void reduce_peaks(unsigned* peaks, unsigned count) {
    unsigned peak = 0;
    for (unsigned i = threadIdx.x; i < count; i += kThreads) {
        if (peaks[i] > peak) peak = peaks[i];
    }
    const unsigned maximum = block_max(peak);
    if (threadIdx.x == 0) peaks[0] = maximum;
}

__global__ void normalize(float* image, const unsigned* peak_bits, size_t count) {
    const float peak = __uint_as_float(peak_bits[0]);
    if (!(peak > 0.0f)) return;

    const size_t step = static_cast<size_t>(gridDim.x) * blockDim.x;
    for (size_t i = static_cast<size_t>(blockIdx.x) * blockDim.x + threadIdx.x;
         i < count; i += step) {
        image[i] = (image[i] / peak) * 255.0f;
    }
}

}  // namespace

extern "C" void solution(const float* input_image, float* output_image,
                         size_t height, size_t width) {
    if (height == 0 || width == 0) return;
    const size_t count = height * width;
    if (height < 3 || width < 3) {
        cudaMemsetAsync(output_image, 0, count * sizeof(float));
        return;
    }

    const size_t required_blocks = 1 + (count - 1) / kThreads;
    const unsigned blocks = static_cast<unsigned>(
        required_blocks < kMaxBlocks ? required_blocks : kMaxBlocks);
    unsigned* peaks = nullptr;
    const size_t scratch_bytes = blocks * sizeof(*peaks);
    const bool async = cudaMallocAsync(&peaks, scratch_bytes, nullptr) == cudaSuccess;
    if (!async) {
        cudaGetLastError();
        if (cudaMalloc(&peaks, scratch_bytes) != cudaSuccess) return;
    }

    if (count <= UINT32_MAX) {
        compute_magnitudes<<<blocks, kThreads>>>(input_image, output_image, peaks, count,
                                                static_cast<uint32_t>(width));
    } else {
        compute_magnitudes<<<blocks, kThreads>>>(input_image, output_image, peaks, count, width);
    }
    if (blocks > 1) reduce_peaks<<<1, kThreads>>>(peaks, blocks);
    normalize<<<blocks, kThreads>>>(output_image, peaks, count);

    if (async) cudaFreeAsync(peaks, nullptr);
    else cudaFree(peaks);
}
