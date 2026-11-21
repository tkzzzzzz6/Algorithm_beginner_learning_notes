#include <cuda_runtime.h>
#include <cstddef>

namespace {

constexpr unsigned kWarpSize = 32;
constexpr unsigned kBlockSize = 1024;

__device__ float warp_prefix_product(float value, unsigned lane) {
    #pragma unroll
    for (unsigned offset = 1; offset < kWarpSize; offset *= 2) {
        const float left = __shfl_up_sync(0xffffffffu, value, offset);
        if (lane >= offset) value *= left;
    }
    return value;
}

template <bool Strided>
__global__ __launch_bounds__(kBlockSize)
void scan_blocks(const float* input, float* output,
                 size_t n, size_t count, size_t stride) {
    __shared__ float warp_products[kBlockSize / kWarpSize];

    const size_t i = static_cast<size_t>(blockIdx.x) * kBlockSize + threadIdx.x;
    const unsigned lane = threadIdx.x % kWarpSize;
    const unsigned warp = threadIdx.x / kWarpSize;
    size_t pos = i;
    float value = 1.0f;
    if (i < count) {
        // At higher levels only the last slot in each lower-level block is scanned.
        if (Strided) pos = i == count - 1 ? n - 1 : (i + 1) * stride - 1;
        value = input[pos];
    }

    value = warp_prefix_product(value, lane);
    if (lane == kWarpSize - 1) warp_products[warp] = value;
    __syncthreads();

    if (warp == 0) {
        const float warp_product = warp_products[lane];
        warp_products[lane] = warp_prefix_product(warp_product, lane);
    }
    __syncthreads();

    if (warp > 0) value *= warp_products[warp - 1];
    if (i < count) output[pos] = value;
}

__global__ void apply_block_products(float* output, size_t count, size_t stride) {
    const size_t begin = (static_cast<size_t>(blockIdx.x) + 1) * kBlockSize;
    const size_t i = begin + threadIdx.x;

    // Block ends already hold their global products and supply the carries.
    if (i < count - 1 && threadIdx.x < kBlockSize - 1) {
        output[(i + 1) * stride - 1] *= output[begin * stride - 1];
    }
}

template <bool Strided>
void scan_level(const float* input, float* output,
                size_t n, size_t count, size_t stride) {
    const auto blocks = static_cast<unsigned>(1 + (count - 1) / kBlockSize);
    scan_blocks<Strided><<<blocks, kBlockSize>>>(input, output, n, count, stride);
    if (blocks > 1) {
        scan_level<true>(output, output, n, blocks, stride * kBlockSize);
        apply_block_products<<<blocks - 1, kBlockSize>>>(output, count, stride);
    }
}

}  // namespace

extern "C" void solution(const float* input, float* output, size_t N) {
    if (N != 0) scan_level<false>(input, output, N, N, 1);
}
