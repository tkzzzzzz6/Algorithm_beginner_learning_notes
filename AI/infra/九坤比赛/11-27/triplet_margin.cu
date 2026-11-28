#include <cuda_runtime.h>
#include <stddef.h>
#include <stdint.h>

namespace {

constexpr unsigned kThreads = 256;
constexpr unsigned kWarpSize = 32;
constexpr unsigned kWarps = kThreads / kWarpSize;
constexpr unsigned kMaxBlocks = 4096;
constexpr float kEpsilon = 1e-6f;

__device__ __forceinline__ float warp_sum(float value) {
    for (unsigned offset = kWarpSize / 2; offset != 0; offset /= 2) {
        value += __shfl_down_sync(0xffffffffu, value, offset);
    }
    return value;
}

__device__ __forceinline__ void add_distances(float a, float p, float n, float2& squares) {
    const float dp = (a - p) + kEpsilon;
    const float dn = (a - n) + kEpsilon;
    squares.x = fmaf(dp, dp, squares.x);
    squares.y = fmaf(dn, dn, squares.y);
}

template <bool Vectorized>
__global__ void triplet_partials(const float* anchor, const float* positive, const float* negative,
                                 float* partials, size_t batch, size_t features, float margin) {
    __shared__ float2 warp_totals[kWarps];
    const unsigned lane = threadIdx.x % kWarpSize;
    const unsigned warp = threadIdx.x / kWarpSize;
    float partial = 0.0f;

    for (size_t row = blockIdx.x; row < batch; row += gridDim.x) {
        const size_t begin = row * features;
        float2 squares = make_float2(0.0f, 0.0f);
        if constexpr (Vectorized) {
            const auto* a = reinterpret_cast<const float4*>(anchor + begin);
            const auto* p = reinterpret_cast<const float4*>(positive + begin);
            const auto* n = reinterpret_cast<const float4*>(negative + begin);
            for (size_t j = threadIdx.x; j < features / 4; j += kThreads) {
                const float4 av = a[j];
                const float4 pv = p[j];
                const float4 nv = n[j];
                add_distances(av.x, pv.x, nv.x, squares);
                add_distances(av.y, pv.y, nv.y, squares);
                add_distances(av.z, pv.z, nv.z, squares);
                add_distances(av.w, pv.w, nv.w, squares);
            }
        } else {
            for (size_t j = threadIdx.x; j < features; j += kThreads) {
                add_distances(anchor[begin + j], positive[begin + j], negative[begin + j], squares);
            }
        }

        squares.x = warp_sum(squares.x);
        squares.y = warp_sum(squares.y);
        if (lane == 0) warp_totals[warp] = squares;
        __syncthreads();
        if (warp == 0) {
            squares = lane < kWarps ? warp_totals[lane] : make_float2(0.0f, 0.0f);
            squares.x = warp_sum(squares.x);
            squares.y = warp_sum(squares.y);
            if (lane == 0) {
                const float hinge = sqrtf(squares.x) - sqrtf(squares.y) + margin;
                partial += hinge < 0.0f ? 0.0f : hinge;
            }
        }
        if (row + gridDim.x < batch) __syncthreads();
    }
    if (threadIdx.x == 0) partials[blockIdx.x] = partial;
}

__global__ void finish_loss(const float* partials, float* output, unsigned count, size_t batch) {
    __shared__ float warp_totals[kWarps];
    const unsigned lane = threadIdx.x % kWarpSize;
    const unsigned warp = threadIdx.x / kWarpSize;
    float sum = 0.0f;
    for (unsigned j = threadIdx.x; j < count; j += kThreads) sum += partials[j];
    sum = warp_sum(sum);
    if (lane == 0) warp_totals[warp] = sum;
    __syncthreads();
    if (warp == 0) {
        sum = warp_sum(lane < kWarps ? warp_totals[lane] : 0.0f);
        if (lane == 0) *output = sum / static_cast<float>(batch);
    }
}

__global__ void write_empty_loss(float* loss, size_t batch, float margin) {
    *loss = batch == 0 ? __int_as_float(0x7fc00000) : (margin < 0.0f ? 0.0f : margin);
}

}  // namespace

extern "C" void solution(const float* anchor, const float* positive, const float* negative,
                         float* loss, size_t B, size_t E, float margin) {
    if (B == 0 || E == 0) {
        write_empty_loss<<<1, 1>>>(loss, B, margin);
        return;
    }

    const unsigned blocks = static_cast<unsigned>(B < kMaxBlocks ? B : kMaxBlocks);
    const size_t bytes = blocks * sizeof(float);
    float* partials = loss;
    bool async = false;
    if (B > 1) {
        async = cudaMallocAsync(&partials, bytes, nullptr) == cudaSuccess;
        if (!async) {
            cudaGetLastError();
            if (cudaMalloc(&partials, bytes) != cudaSuccess) return;
        }
    }

    const uintptr_t addresses = reinterpret_cast<uintptr_t>(anchor) |
                                reinterpret_cast<uintptr_t>(positive) |
                                reinterpret_cast<uintptr_t>(negative);
    if (E % 4 == 0 && addresses % alignof(float4) == 0) {
        triplet_partials<true><<<blocks, kThreads>>>(anchor, positive, negative, partials, B, E, margin);
    } else {
        triplet_partials<false><<<blocks, kThreads>>>(anchor, positive, negative, partials, B, E, margin);
    }

    if (B > 1) {
        finish_loss<<<1, kThreads>>>(partials, loss, blocks, B);
        if (async) cudaFreeAsync(partials, nullptr);
        else cudaFree(partials);
    }
}
