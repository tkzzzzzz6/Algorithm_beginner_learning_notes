#include <cuda_runtime.h>
#include <stddef.h>
#include <stdint.h>

namespace {

constexpr unsigned kMaxGridY = 65535;

__device__ float4 scale4(float4 v, float scale) {
    return make_float4(v.x * scale, v.y * scale, v.z * scale, v.w * scale);
}

template <unsigned Threads, unsigned Vectors, int Cache = 0>
__global__ void scale_aligned_rows(const float* diagonal,
                                   const float4* input, float4* output,
                                   size_t rows, size_t stride) {
    const size_t base_col = static_cast<size_t>(blockIdx.x) * Threads * Vectors + threadIdx.x;
    for (size_t row = blockIdx.y; row < rows; row += gridDim.y) {
        const float scale = diagonal[row];
        const size_t index = row * stride + base_col;
        #pragma unroll
        for (unsigned vector = 0; vector < Vectors; ++vector) {
            const size_t position = index + vector * Threads;
            const float4 value = Cache == 2 ? __ldcg(input + position) : input[position];
            const float4 result = scale4(value, scale);
            if (Cache != 0) __stcs(output + position, result);
            else output[position] = result;
        }
    }
}

__global__ void scale_elements(const float* diagonal, const float* input, float* output,
                               size_t rows, size_t cols) {
    const size_t col = static_cast<size_t>(blockIdx.x) * blockDim.x + threadIdx.x;
    if (col >= cols) return;
    for (size_t row = blockIdx.y; row < rows; row += gridDim.y) {
        const size_t index = row * cols + col;
        output[index] = diagonal[row] * input[index];
    }
}

template <unsigned Threads, unsigned Vectors, int Cache = 0>
void launch_tiled(const float* diagonal, const float* input, float* output,
                  size_t rows, size_t cols, unsigned grid_y) {
    const dim3 grid(static_cast<unsigned>(cols / (4 * Threads * Vectors)), grid_y);
    scale_aligned_rows<Threads, Vectors, Cache><<<grid, Threads>>>(
        diagonal, reinterpret_cast<const float4*>(input), reinterpret_cast<float4*>(output),
        rows, cols / 4);
}

}  // namespace

extern "C" void solution(const float* diagonal_a, const float* input_b,
                         float* output_c, size_t n, size_t m) {
    if (n == 0 || m == 0) return;
    const unsigned grid_y = static_cast<unsigned>(n < kMaxGridY ? n : kMaxGridY);
    const bool aligned = (reinterpret_cast<uintptr_t>(input_b) | reinterpret_cast<uintptr_t>(output_c))
        % alignof(float4) == 0;
    if (aligned && m <= 2048 && m % 1024 == 0) {
        launch_tiled<256, 1>(diagonal_a, input_b, output_c, n, m, grid_y);
    } else if (aligned && m % 4096 == 0) {
        launch_tiled<256, 4>(diagonal_a, input_b, output_c, n, m, grid_y);
    } else if (aligned && m % 2048 == 0) {
        launch_tiled<128, 4, 2>(diagonal_a, input_b, output_c, n, m, grid_y);
    } else {
        constexpr unsigned kThreads = 256;
        const dim3 grid(static_cast<unsigned>(1 + (m - 1) / kThreads), grid_y);
        scale_elements<<<grid, kThreads>>>(diagonal_a, input_b, output_c, n, m);
    }
}



