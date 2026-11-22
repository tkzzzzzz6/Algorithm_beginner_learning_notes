#include <cuda_runtime.h>
#include <cstddef>
#include <cstdint>

namespace {

constexpr unsigned kThreads = 256;
constexpr unsigned kWarpSize = 32;
constexpr unsigned kMaxBlocks = 1024;

__device__ float warp_sum(float sum) {
    #pragma unroll
    for (int step = kWarpSize / 2; step > 0; step /= 2) {
        sum += __shfl_down_sync(0xffffffffu, sum, step);
    }
    return sum;
}

__device__ float block_sum(float sum) {
    __shared__ float warp_sums[kThreads / kWarpSize];
    const unsigned lane = threadIdx.x % kWarpSize;
    const unsigned warp = threadIdx.x / kWarpSize;
    sum = warp_sum(sum);
    if (lane == 0) warp_sums[warp] = sum;
    __syncthreads();

    if (warp == 0) {
        sum = lane < kThreads / kWarpSize ? warp_sums[lane] : 0.0f;
        sum = warp_sum(sum);
    }
    return sum;
}

__device__ void accumulate_squares(float& sum, float value) {
    sum = fmaf(value, value, sum);
}

__device__ void accumulate_squares(float4& sum, float4 value) {
    accumulate_squares(sum.x, value.x);
    accumulate_squares(sum.y, value.y);
    accumulate_squares(sum.z, value.z);
    accumulate_squares(sum.w, value.w);
}

__device__ float collapse(float sum) {
    return sum;
}

__device__ float collapse(float4 sum) {
    return (sum.x + sum.y) + (sum.z + sum.w);
}

__device__ float scale(float value, float inverse_norm) {
    return value * inverse_norm;
}

__device__ float4 scale(float4 value, float inverse_norm) {
    return make_float4(value.x * inverse_norm, value.y * inverse_norm,
                       value.z * inverse_norm, value.w * inverse_norm);
}

__global__ void normalize_small(const float* input, float* output, size_t count) {
    __shared__ float inverse_norm;
    float sum = 0.0f;
    for (size_t i = threadIdx.x; i < count; i += blockDim.x) {
        accumulate_squares(sum, input[i]);
    }
    sum = block_sum(sum);
    if (threadIdx.x == 0) inverse_norm = 1.0f / sqrtf(sum);
    __syncthreads();

    for (size_t i = threadIdx.x; i < count; i += blockDim.x) {
        output[i] = scale(input[i], inverse_norm);
    }
}

template <typename T>
__global__ void reduce_squares(const T* input, size_t count, float* partials) {
    const size_t first = static_cast<size_t>(blockIdx.x) * blockDim.x + threadIdx.x;
    const size_t stride = static_cast<size_t>(gridDim.x) * blockDim.x;
    T sum{};
    for (size_t i = first; i < count; i += stride) {
        accumulate_squares(sum, input[i]);
    }
    const float total = block_sum(collapse(sum));
    if (threadIdx.x == 0) partials[blockIdx.x] = total;
}

__global__ void finalize_inverse_norm(float* partials, unsigned count) {
    float sum = 0.0f;
    for (unsigned i = threadIdx.x; i < count; i += blockDim.x) sum += partials[i];
    sum = block_sum(sum);
    if (threadIdx.x == 0) partials[0] = 1.0f / sqrtf(sum);
}

template <typename T>
__global__ void normalize(const T* input, T* output, size_t count, const float* inverse_norm) {
    const size_t first = static_cast<size_t>(blockIdx.x) * blockDim.x + threadIdx.x;
    const size_t stride = static_cast<size_t>(gridDim.x) * blockDim.x;
    const float factor = *inverse_norm;
    for (size_t i = first; i < count; i += stride) {
        output[i] = scale(input[i], factor);
    }
}

template <typename T>
void normalize_large(const T* input, T* output, size_t count) {
    const size_t tiles = 1 + (count - 1) / (kThreads * 4);
    const auto blocks = static_cast<unsigned>(tiles < kMaxBlocks ? tiles : kMaxBlocks);
    float* partials = nullptr;
    bool stream_ordered = false;
#if CUDART_VERSION >= 11020
    int device = 0;
    int supports_pools = 0;
    if (cudaGetDevice(&device) != cudaSuccess ||
        cudaDeviceGetAttribute(&supports_pools, cudaDevAttrMemoryPoolsSupported, device) != cudaSuccess) {
        return;
    }
    stream_ordered = supports_pools != 0;
    if (stream_ordered && cudaMallocAsync(&partials, blocks * sizeof(float), nullptr) != cudaSuccess) {
        return;
    }
#endif
    if (!stream_ordered && cudaMalloc(&partials, blocks * sizeof(float)) != cudaSuccess) return;

    reduce_squares<<<blocks, kThreads>>>(input, count, partials);
    finalize_inverse_norm<<<1, kThreads>>>(partials, blocks);
    normalize<<<blocks, kThreads>>>(input, output, count, partials);

#if CUDART_VERSION >= 11020
    if (stream_ordered) {
        cudaFreeAsync(partials, nullptr);
        return;
    }
#endif
    cudaFree(partials);
}

}  // namespace

extern "C" void solution(const float* X, float* Y, size_t size) {
    if (size == 0) return;
    if (size <= 1024) {
        normalize_small<<<1, kThreads>>>(X, Y, size);
        return;
    }

    const bool aligned = reinterpret_cast<std::uintptr_t>(X) % alignof(float4) == 0 &&
                         reinterpret_cast<std::uintptr_t>(Y) % alignof(float4) == 0;
    if (aligned && size % 4 == 0) {
        normalize_large(reinterpret_cast<const float4*>(X), reinterpret_cast<float4*>(Y), size / 4);
    } else {
        normalize_large(X, Y, size);
    }
}
