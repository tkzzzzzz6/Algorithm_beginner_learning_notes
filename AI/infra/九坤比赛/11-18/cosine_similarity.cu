#include <cuda_runtime.h>
#include <stddef.h>
#include <stdint.h>

namespace {

constexpr unsigned int kThreads = 128;
constexpr unsigned int kWarpSize = 32;
constexpr float kEps = 1.0e-8f;

struct Sums {
    float dot;
    float x_squared;
    float y_squared;

    __device__ void accumulate(float x, float y) {
        dot = fmaf(x, y, dot);
        x_squared = fmaf(x, x, x_squared);
        y_squared = fmaf(y, y, y_squared);
    }

    __device__ void accumulate(float4 x, float4 y) {
        accumulate(x.x, y.x);
        accumulate(x.y, y.y);
        accumulate(x.z, y.z);
        accumulate(x.w, y.w);
    }
};

template <typename T>
__global__ void cosine_rows(const T* __restrict__ predictions,
                            const T* __restrict__ targets,
                            float* __restrict__ output, size_t columns) {
    const size_t row = blockIdx.x;
    const unsigned int lane = threadIdx.x % kWarpSize;
    const unsigned int warp = threadIdx.x / kWarpSize;
    const size_t row_start = row * columns;
    Sums sums{};

    #pragma unroll 4
    for (size_t column = threadIdx.x; column < columns; column += kThreads) {
        sums.accumulate(predictions[row_start + column], targets[row_start + column]);
    }

    #pragma unroll
    for (int offset = kWarpSize / 2; offset > 0; offset /= 2) {
        sums.dot += __shfl_down_sync(0xffffffffu, sums.dot, offset);
        sums.x_squared += __shfl_down_sync(0xffffffffu, sums.x_squared, offset);
        sums.y_squared += __shfl_down_sync(0xffffffffu, sums.y_squared, offset);
    }

    __shared__ Sums warp_sums[kThreads / kWarpSize];
    if (lane == 0) warp_sums[warp] = sums;
    __syncthreads();

    if (threadIdx.x == 0) {
        #pragma unroll
        for (unsigned int w = 1; w < kThreads / kWarpSize; ++w) {
            sums.dot += warp_sums[w].dot;
            sums.x_squared += warp_sums[w].x_squared;
            sums.y_squared += warp_sums[w].y_squared;
        }

        const float norm_x = fmaxf(sqrtf(sums.x_squared), kEps);
        const float norm_y = fmaxf(sqrtf(sums.y_squared), kEps);
        output[row] = 1.0f - sums.dot / (norm_x * norm_y);
    }
}

}  // namespace

extern "C" void solution(const float* predictions, const float* targets,
                         float* output, size_t n, size_t d) {
    if (n == 0) return;

    const auto blocks = static_cast<unsigned int>(n);
    if (d % 4 == 0 &&
        reinterpret_cast<uintptr_t>(predictions) % alignof(float4) == 0 &&
        reinterpret_cast<uintptr_t>(targets) % alignof(float4) == 0) {
        cosine_rows<<<blocks, kThreads>>>(reinterpret_cast<const float4*>(predictions),
                                        reinterpret_cast<const float4*>(targets), output, d / 4);
    } else {
        cosine_rows<<<blocks, kThreads>>>(predictions, targets, output, d);
    }
}
