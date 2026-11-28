#include <cuda_runtime.h>
#include <stddef.h>

namespace {

constexpr unsigned kWarpSize = 32;
constexpr unsigned kWarps = 8;
constexpr unsigned kThreads = kWarpSize * kWarps;
constexpr unsigned kGrid = 512;

template <bool Maximum>
__device__ __forceinline__ float warp_reduce(float value) {
    #pragma unroll
    for (unsigned offset = kWarpSize / 2; offset != 0; offset /= 2) {
        const float other = __shfl_down_sync(0xffffffffu, value, offset);
        value = Maximum ? fmaxf(value, other) : value + other;
    }
    return __shfl_sync(0xffffffffu, value, 0);
}

template <unsigned Items>
__device__ void contiguous_cached(const float* input, float* output,
                                  size_t rows, size_t width) {
    const unsigned lane = threadIdx.x % kWarpSize;
    for (size_t row = blockIdx.x * kWarps + threadIdx.x / kWarpSize;
         row < rows; row += gridDim.x * kWarps) {
        const size_t start = row * width;
        float values[Items];
        float maximum = -__int_as_float(0x7f800000);
        #pragma unroll
        for (unsigned item = 0; item < Items; ++item) {
            const unsigned col = lane + item * kWarpSize;
            values[item] = col < width ? input[start + col] : -__int_as_float(0x7f800000);
            maximum = fmaxf(maximum, values[item]);
        }
        maximum = warp_reduce<true>(maximum);

        float sum = 0.0f;
        #pragma unroll
        for (unsigned item = 0; item < Items; ++item) {
            const unsigned col = lane + item * kWarpSize;
            values[item] = col < width ? __expf(values[item] - maximum) : 0.0f;
            sum += values[item];
        }
        const float inverse = 1.0f / warp_reduce<false>(sum);
        #pragma unroll
        for (unsigned item = 0; item < Items; ++item) {
            const unsigned col = lane + item * kWarpSize;
            if (col < width) output[start + col] = values[item] * inverse;
        }
    }
}

__device__ void contiguous_general(const float* input, float* output,
                                   size_t rows, size_t width) {
    const unsigned lane = threadIdx.x % kWarpSize;
    for (size_t row = blockIdx.x * kWarps + threadIdx.x / kWarpSize;
         row < rows; row += gridDim.x * kWarps) {
        const size_t start = row * width;
        float maximum = -__int_as_float(0x7f800000);
        for (size_t col = lane; col < width; col += kWarpSize) {
            maximum = fmaxf(maximum, input[start + col]);
        }
        maximum = warp_reduce<true>(maximum);

        float sum = 0.0f;
        for (size_t col = lane; col < width; col += kWarpSize) {
            sum += __expf(input[start + col] - maximum);
        }
        const float inverse = 1.0f / warp_reduce<false>(sum);
        for (size_t col = lane; col < width; col += kWarpSize) {
            output[start + col] = __expf(input[start + col] - maximum) * inverse;
        }
    }
}

__device__ void strided_columns(const float* input, float* output, size_t outer,
                                size_t width, size_t inner) {
    __shared__ float partials[kWarps][kWarpSize];
    __shared__ float reduced[kWarpSize];
    const unsigned lane = threadIdx.x % kWarpSize;
    const unsigned warp = threadIdx.x / kWarpSize;
    const size_t tiles_per_outer = 1 + (inner - 1) / kWarpSize;
    for (size_t tile = blockIdx.x; tile < outer * tiles_per_outer; tile += gridDim.x) {
        const size_t col = tile % tiles_per_outer * kWarpSize + lane;
        const size_t start = tile / tiles_per_outer * width * inner + col;

        float maximum = -__int_as_float(0x7f800000);
        if (col < inner) {
            for (size_t dim = warp; dim < width; dim += kWarps) {
                maximum = fmaxf(maximum, input[start + dim * inner]);
            }
        }
        partials[warp][lane] = maximum;
        __syncthreads();
        if (warp == 0) {
            #pragma unroll
            for (unsigned i = 1; i < kWarps; ++i) {
                maximum = fmaxf(maximum, partials[i][lane]);
            }
            reduced[lane] = maximum;
        }
        __syncthreads();
        maximum = reduced[lane];

        float sum = 0.0f;
        if (col < inner) {
            for (size_t dim = warp; dim < width; dim += kWarps) {
                sum += __expf(input[start + dim * inner] - maximum);
            }
        }
        partials[warp][lane] = sum;
        __syncthreads();
        if (warp == 0) {
            #pragma unroll
            for (unsigned i = 1; i < kWarps; ++i) {
                sum += partials[i][lane];
            }
            reduced[lane] = 1.0f / sum;
        }
        __syncthreads();
        const float inverse = reduced[lane];
        if (col < inner) {
            for (size_t dim = warp; dim < width; dim += kWarps) {
                const size_t index = start + dim * inner;
                output[index] = __expf(input[index] - maximum) * inverse;
            }
        }
    }
}

__global__ void softmax(const float* input, float* output, const size_t* shape,
                        size_t ndim, size_t axis) {
    __shared__ size_t outer, width, inner;
    if (threadIdx.x == 0) {
        outer = 1;
        for (size_t i = 0; i < axis; ++i) outer *= shape[i];
        width = shape[axis];
        inner = 1;
        for (size_t i = axis + 1; i < ndim; ++i) inner *= shape[i];
    }
    __syncthreads();
    if (outer == 0 || width == 0 || inner == 0) return;

    if (inner != 1) {
        strided_columns(input, output, outer, width, inner);
    } else if (width <= kWarpSize) {
        contiguous_cached<1>(input, output, outer, width);
    } else if (width == 256) {
        contiguous_cached<8>(input, output, outer, width);
    } else if (width == 512) {
        contiguous_cached<16>(input, output, outer, width);
    } else {
        contiguous_general(input, output, outer, width);
    }
}

}  // namespace

extern "C" void solution(const float* input, int dim, float* output, const size_t* shape, size_t ndim) {
    size_t axis;
    if (dim < 0) {
        const size_t distance = static_cast<size_t>(-static_cast<long long>(dim));
        if (distance > ndim) return;
        axis = ndim - distance;
    } else {
        axis = static_cast<size_t>(dim);
    }
    if (axis >= ndim) return;
    softmax<<<kGrid, kThreads>>>(input, output, shape, ndim, axis);
}
