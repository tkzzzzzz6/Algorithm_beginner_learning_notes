#include <cuda_runtime.h>
#include <cstddef>
#include <cstdint>

namespace {

constexpr unsigned kThreads = 256;
constexpr unsigned kWarpSize = 32;
constexpr unsigned kWarps = kThreads / kWarpSize;
constexpr unsigned kMaxBlocks = 768;
constexpr int kSharedBins = 256;
constexpr size_t kExactFloatCount = size_t{1} << 24;

template <typename Counter>
__device__ __forceinline__ void record_pixel(Counter* bins, float value) {
    const unsigned bin = static_cast<unsigned>(value);
#if defined(__CUDA_ARCH__) && __CUDA_ARCH__ >= 700
    const unsigned peers = __match_any_sync(__activemask(), bin);
    const int lane = threadIdx.x % kWarpSize;
    if (lane == __ffs(peers) - 1) {
        atomicAdd(&bins[bin], static_cast<Counter>(__popc(peers)));
    }
#else
    atomicAdd(&bins[bin], Counter{1});
#endif
}

template <typename Counter>
__device__ __forceinline__ void record_pixel(Counter* bins, float4 values) {
    record_pixel(bins, values.x);
    record_pixel(bins, values.y);
    record_pixel(bins, values.z);
    record_pixel(bins, values.w);
}

template <typename Pixel, typename Counter, bool UseShared>
__global__ void count_pixels(const Pixel* image, size_t count, int num_bins, Counter* output) {
    extern __shared__ unsigned block_bins[];
    const unsigned stride = blockDim.x;
    const size_t first = static_cast<size_t>(blockIdx.x) * stride + threadIdx.x;
    const size_t grid_stride = static_cast<size_t>(gridDim.x) * stride;

    if (UseShared) {
        const unsigned entries = kWarps * num_bins;
        for (unsigned i = threadIdx.x; i < entries; i += stride) block_bins[i] = 0;
        __syncthreads();

        unsigned* local_bins = block_bins + (threadIdx.x / kWarpSize) * num_bins;
        for (size_t i = first; i < count; i += grid_stride) {
            record_pixel(local_bins, image[i]);
        }
        __syncthreads();

        for (int bin = threadIdx.x; bin < num_bins; bin += stride) {
            unsigned total = 0;
            #pragma unroll
            for (unsigned warp = 0; warp < kWarps; ++warp) {
                total += block_bins[warp * num_bins + bin];
            }
            if (total != 0) atomicAdd(&output[bin], static_cast<Counter>(total));
        }
    } else {
        for (size_t i = first; i < count; i += grid_stride) {
            record_pixel(output, image[i]);
        }
    }
}

__global__ void convert_counts(const unsigned* counts, float* output, size_t num_bins) {
    const size_t first = static_cast<size_t>(blockIdx.x) * blockDim.x + threadIdx.x;
    const size_t stride = static_cast<size_t>(gridDim.x) * blockDim.x;
    for (size_t bin = first; bin < num_bins; bin += stride) {
        output[bin] = static_cast<float>(counts[bin]);
    }
}

__device__ unsigned long long warp_sum(unsigned long long count) {
    #pragma unroll
    for (unsigned delta = kWarpSize / 2; delta; delta /= 2) {
        count += __shfl_down_sync(0xffffffffu, count, delta);
    }
    return count;
}

__global__ void count_wide_bins(const float* image, size_t count, float* output) {
    __shared__ unsigned long long warp_totals[kWarps];
    const unsigned bin = blockIdx.x;
    const unsigned lane = threadIdx.x % kWarpSize;
    unsigned long long total = 0;
    for (size_t i = threadIdx.x; i < count; i += blockDim.x) {
        total += static_cast<unsigned>(image[i]) == bin;
    }
    total = warp_sum(total);
    if (lane == 0) warp_totals[threadIdx.x / kWarpSize] = total;
    __syncthreads();
    if (threadIdx.x < kWarpSize) {
        total = warp_sum(lane < kWarps ? warp_totals[lane] : 0);
        if (lane == 0) output[bin] = static_cast<float>(total);
    }
}

template <typename Pixel, typename Counter>
void launch_counts(const Pixel* image, size_t count, int num_bins, Counter* output,
                   unsigned blocks) {
    if (num_bins <= kSharedBins) {
        const size_t shared_bytes = kWarps * num_bins * sizeof(unsigned);
        count_pixels<Pixel, Counter, true><<<blocks, kThreads, shared_bytes>>>(
            image, count, num_bins, output);
    } else {
        count_pixels<Pixel, Counter, false><<<blocks, kThreads>>>(image, count, num_bins, output);
    }
}

template <typename Counter>
void launch_image(const float* image, size_t count, int num_bins, Counter* output) {
    const size_t tiles = 1 + (count - 1) / (kThreads * 16);
    const unsigned blocks = static_cast<unsigned>(tiles < kMaxBlocks ? tiles : kMaxBlocks);
    const bool aligned = reinterpret_cast<std::uintptr_t>(image) % alignof(float4) == 0;
    if (aligned && count % 4 == 0) {
        launch_counts(reinterpret_cast<const float4*>(image), count / 4, num_bins, output, blocks);
    } else {
        launch_counts(image, count, num_bins, output, blocks);
    }
}

}  // namespace

extern "C" void solution(const float* image, int num_bins, float* histogram,
                         size_t height, size_t width) {
    if (num_bins <= 0) return;
    const size_t count = height * width;
    if (count > UINT32_MAX) {
        count_wide_bins<<<num_bins, kThreads>>>(image, count, histogram);
        return;
    }

    cudaMemsetAsync(histogram, 0, static_cast<size_t>(num_bins) * sizeof(float));
    if (count == 0) return;
    if (count <= kExactFloatCount) {
        launch_image(image, count, num_bins, histogram);
    } else {
        // Keep counts integral until the final conversion when FP32 increments can round.
        auto* counts = reinterpret_cast<unsigned*>(histogram);
        launch_image(image, count, num_bins, counts);
        const unsigned tiles = 1 + (static_cast<unsigned>(num_bins) - 1) / kThreads;
        const unsigned blocks = tiles < kMaxBlocks ? tiles : kMaxBlocks;
        convert_counts<<<blocks, kThreads>>>(counts, histogram, num_bins);
    }
}
