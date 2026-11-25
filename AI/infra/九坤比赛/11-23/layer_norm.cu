#include <cuda_runtime.h>
#include <stddef.h>

namespace {

constexpr unsigned kThreads = 256;
constexpr unsigned kWarpSize = 32;
constexpr unsigned kWarps = kThreads / kWarpSize;
constexpr size_t kItemsPerBlock = 2048;
constexpr unsigned kMaxBlocksPerSample = 256;
constexpr double kEpsilon = 1e-5;

__device__ double2 warp_sum(double2 value) {
    #pragma unroll
    for (int delta = kWarpSize / 2; delta > 0; delta /= 2) {
        value.x += __shfl_down_sync(0xffffffffu, value.x, delta);
        value.y += __shfl_down_sync(0xffffffffu, value.y, delta);
    }
    return value;
}

__device__ double2 block_sum(double2 value) {
    __shared__ double2 warp_totals[kWarps];
    const unsigned lane = threadIdx.x % kWarpSize;
    const unsigned warp = threadIdx.x / kWarpSize;
    value = warp_sum(value);
    if (lane == 0) warp_totals[warp] = value;
    __syncthreads();

    if (warp == 0) {
        value = lane < kWarps ? warp_totals[lane] : make_double2(0.0, 0.0);
        value = warp_sum(value);
    }
    return value;
}

__global__ void partial_moments(const float* input, double2* partials,
                                size_t features, unsigned blocks_per_sample) {
    const size_t sample = blockIdx.x / blocks_per_sample;
    const unsigned part = blockIdx.x % blocks_per_sample;
    const float* row = input + sample * features;
    const double origin = row[0];
    const size_t step = static_cast<size_t>(blocks_per_sample) * kThreads;
    double2 moments = make_double2(0.0, 0.0);

    // Center at the first value before forming squares to limit cancellation.
    for (size_t j = part * kThreads + threadIdx.x; j < features; j += step) {
        const double shifted = static_cast<double>(row[j]) - origin;
        moments.x += shifted;
        moments.y = fma(shifted, shifted, moments.y);
    }
    moments = block_sum(moments);
    if (threadIdx.x == 0) partials[blockIdx.x] = moments;
}

__global__ void finish_statistics(const float* input, const double2* partials,
                                   double2* statistics, size_t features,
                                   unsigned blocks_per_sample) {
    const size_t sample = blockIdx.x;
    const double2 value = threadIdx.x < blocks_per_sample
        ? partials[sample * blocks_per_sample + threadIdx.x] : make_double2(0.0, 0.0);
    const double2 totals = block_sum(value);
    if (threadIdx.x == 0) {
        const double shifted_mean = totals.x / static_cast<double>(features);
        const double variance = fma(-shifted_mean, shifted_mean,
                                    totals.y / static_cast<double>(features));
        const double mean = static_cast<double>(input[sample * features]) + shifted_mean;
        const double inv_stddev = 1.0 / sqrt((variance < 0.0 ? 0.0 : variance) + kEpsilon);
        statistics[sample] = make_double2(mean, inv_stddev);
    }
}

__global__ void normalize_rows(const float* input, const float* gamma, const float* beta,
                               float* output, const double2* statistics, size_t features,
                               unsigned blocks_per_sample) {
    const size_t sample = blockIdx.x / blocks_per_sample;
    const unsigned part = blockIdx.x % blocks_per_sample;
    const size_t base = sample * features;
    const size_t step = static_cast<size_t>(blocks_per_sample) * kThreads;
    const double2 stats = statistics[sample];
    for (size_t j = part * kThreads + threadIdx.x; j < features; j += step) {
        const double standard = (static_cast<double>(input[base + j]) - stats.x) * stats.y;
        output[base + j] = static_cast<float>(fma(standard, static_cast<double>(gamma[j]),
                                                  static_cast<double>(beta[j])));
    }
}

}  // namespace

extern "C" void solution(const float* X, const float* gamma, const float* beta, float* Y,
                         size_t B, size_t F, size_t D1, size_t D2) {
    if (B == 0 || F == 0 || D1 == 0 || D2 == 0) return;

    const size_t features = F * D1 * D2;
    const size_t needed_blocks = 1 + (features - 1) / kItemsPerBlock;
    const auto blocks_per_sample = static_cast<unsigned>(
        needed_blocks < kMaxBlocksPerSample ? needed_blocks : kMaxBlocksPerSample);
    const size_t partial_count = B * blocks_per_sample;
    const size_t scratch_bytes = (partial_count + B) * sizeof(double2);
    double2* partials = nullptr;
    const bool async = cudaMallocAsync(&partials, scratch_bytes, nullptr) == cudaSuccess;
    if (!async) {
        cudaGetLastError();
        if (cudaMalloc(&partials, scratch_bytes) != cudaSuccess) return;
    }

    double2* statistics = partials + partial_count;
    const auto grid = static_cast<unsigned>(partial_count);
    partial_moments<<<grid, kThreads>>>(X, partials, features, blocks_per_sample);
    finish_statistics<<<static_cast<unsigned>(B), kThreads>>>(
        X, partials, statistics, features, blocks_per_sample);
    normalize_rows<<<grid, kThreads>>>(X, gamma, beta, Y, statistics, features, blocks_per_sample);

    if (async) cudaFreeAsync(partials, nullptr);
    else cudaFree(partials);
}
