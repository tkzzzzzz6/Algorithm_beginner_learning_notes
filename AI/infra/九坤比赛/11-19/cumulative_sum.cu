#include <cuda_runtime.h>
#include <cooperative_groups.h>
#include <stddef.h>
#include <stdint.h>

namespace {

constexpr unsigned kThreads = 256;
constexpr unsigned kValues = 4;
constexpr unsigned kTile = kThreads * kValues;

template <unsigned Width>
__device__ float warp_scan(float x, unsigned lane) {
    #pragma unroll
    for (unsigned d = 1; d < Width; d *= 2) {
        const float left = __shfl_up_sync(0xffffffffu, x, d);
        if (lane >= d) x += left;
    }
    return x;
}

template <unsigned Threads>
__device__ float block_offset(float x, float* warp_totals) {
    constexpr unsigned warps = Threads / 32;
    const unsigned lane = threadIdx.x % 32;
    const unsigned warp = threadIdx.x / 32;
    const float inclusive = warp_scan<32>(x, lane);
    const float previous = __shfl_up_sync(0xffffffffu, inclusive, 1);
    if (lane == 31) warp_totals[warp] = inclusive;
    __syncthreads();

    if (warp == 0) {
        const float total = lane < warps ? warp_totals[lane] : 0.0f;
        const float cumulative = warp_scan<warps>(total, lane);
        if (lane < warps) warp_totals[lane] = cumulative;
    }
    __syncthreads();

    return (lane == 0 ? 0.0f : previous) +
           (warp == 0 ? 0.0f : warp_totals[warp - 1]);
}

template <bool Vector>
__global__ void scan_tiles(const float* input, float* output, size_t n) {
    __shared__ float totals[kThreads / 32];
    const size_t group = static_cast<size_t>(blockIdx.x) * kThreads + threadIdx.x;
    const size_t i = group * kValues;
    float4 v{};
    if (Vector) {
        v = reinterpret_cast<const float4*>(input)[group];
    } else if (i < n) {
        v.x = input[i];
        if (i + 1 < n) v.y = input[i + 1];
        if (i + 2 < n) v.z = input[i + 2];
        if (i + 3 < n) v.w = input[i + 3];
    }

    const float xy = v.x + v.y;
    const float xyz = xy + v.z;
    const float xyzw = xy + (v.z + v.w);
    const float prefix = block_offset<kThreads>(xyzw, totals);
    if (threadIdx.x != 0) {
        v.x += prefix;
        v.y = xy + prefix;
        v.z = xyz + prefix;
        v.w = xyzw + prefix;
    } else {
        v.y = xy;
        v.z = xyz;
        v.w = xyzw;
    }

    if (Vector) {
        reinterpret_cast<float4*>(output)[group] = v;
    } else if (i < n) {
        output[i] = v.x;
        if (i + 1 < n) output[i + 1] = v.y;
        if (i + 2 < n) output[i + 2] = v.z;
        if (i + 3 < n) output[i + 3] = v.w;
    }
}

__global__ void scan_ends(float* output, size_t n, size_t count, size_t stride) {
    __shared__ float totals[kThreads / 32];
    const size_t begin = (static_cast<size_t>(blockIdx.x) * kThreads + threadIdx.x) * kValues;
    size_t pos[kValues] = {};
    float values[kValues] = {};
    #pragma unroll
    for (unsigned j = 0; j < kValues; ++j) {
        const size_t i = begin + j;
        if (i < count) {
            pos[j] = i == count - 1 ? n - 1 : (i + 1) * stride - 1;
            values[j] = output[pos[j]];
        }
    }

    const float xy = values[0] + values[1];
    const float xyz = xy + values[2];
    const float xyzw = xy + (values[2] + values[3]);
    const float prefix = block_offset<kThreads>(xyzw, totals);
    const float sums[kValues] = {values[0] + prefix, xy + prefix, xyz + prefix, xyzw + prefix};
    #pragma unroll
    for (unsigned j = 0; j < kValues; ++j) {
        if (begin + j < count) output[pos[j]] = sums[j];
    }
}

__global__ void add_to_ends(float* output, size_t count, size_t stride) {
    const size_t begin = (static_cast<size_t>(blockIdx.x) + 1) * kTile;
    const size_t local = threadIdx.x * kValues;
    const float prefix = output[begin * stride - 1];
    #pragma unroll
    for (unsigned j = 0; j < kValues; ++j) {
        const size_t i = begin + local + j;
        if (i < count - 1 && local + j < kTile - 1) {
            output[(i + 1) * stride - 1] += prefix;
        }
    }
}

template <bool Vector>
__global__ void add_to_tiles(float* output, size_t n) {
    const size_t begin = (static_cast<size_t>(blockIdx.x) + 1) * kTile;
    const size_t i = begin + static_cast<size_t>(threadIdx.x) * kValues;
    if (i >= n - 1) return;
    const float prefix = output[begin - 1];
    if (Vector && threadIdx.x != kThreads - 1) {
        float4* packed = reinterpret_cast<float4*>(output);
        float4 v = packed[i / kValues];
        v.x += prefix;
        v.y += prefix;
        v.z += prefix;
        v.w += prefix;
        packed[i / kValues] = v;
    } else {
        #pragma unroll
        for (unsigned j = 0; j < kValues; ++j) {
            const size_t at = i + j;
            if (at < n - 1 && (threadIdx.x != kThreads - 1 || j != kValues - 1)) {
                output[at] += prefix;
            }
        }
    }
}

void scan_tile_ends(float* output, size_t n, size_t count, size_t stride) {
    const auto blocks = static_cast<unsigned>(1 + (count - 1) / kTile);
    scan_ends<<<blocks, kThreads>>>(output, n, count, stride);
    if (blocks > 1) {
        scan_tile_ends(output, n, blocks, stride * kTile);
        add_to_ends<<<blocks - 1, kThreads>>>(output, count, stride);
    }
}

constexpr unsigned kWarp = 32;
constexpr unsigned kWarps = kThreads / kWarp;

__device__ float warp_sum(float x) {
    #pragma unroll
    for (unsigned d = 16; d != 0; d /= 2) {
        x += __shfl_down_sync(0xffffffffu, x, d);
    }
    return x;
}

constexpr unsigned kCoopTile = 8 * kThreads;

__global__ void scan_cooperative(const float* input, float* output) {
    __shared__ float warp_totals[kWarps];
    __shared__ float tile_offset;
    const unsigned lane = threadIdx.x % kWarp;
    const unsigned warp = threadIdx.x / kWarp;
    const size_t group = static_cast<size_t>(blockIdx.x) * kThreads + threadIdx.x;
    const float4* source = reinterpret_cast<const float4*>(input);
    float4 a = source[2 * group], b = source[2 * group + 1];
    const float a0 = a.x;
    const float a1 = a.x + a.y;
    const float a2 = a1 + a.z;
    const float a3 = a1 + (a.z + a.w);
    const float b0 = a3 + b.x;
    const float b1 = a3 + (b.x + b.y);
    const float b2 = a3 + ((b.x + b.y) + b.z);
    const float b3 = a3 + ((b.x + b.y) + (b.z + b.w));

    const float inclusive = warp_scan<kWarp>(b3, lane);
    const float previous = __shfl_up_sync(0xffffffffu, inclusive, 1);
    if (lane == kWarp - 1) warp_totals[warp] = inclusive;
    __syncthreads();
    if (warp == 0) {
        const float prefix = warp_scan<kWarps>(lane < kWarps ? warp_totals[lane] : 0.0f, lane);
        if (lane < kWarps) warp_totals[lane] = prefix;
    }
    __syncthreads();

    float local_prefix = 0.0f;
    if (warp > 0) local_prefix += warp_totals[warp - 1];
    if (lane > 0) local_prefix += previous;
    if (threadIdx.x == kThreads - 1) {
        output[blockIdx.x] = warp_totals[kWarps - 1];
    }

    auto grid = cooperative_groups::this_grid();
    grid.sync();
    if (warp == 0) {
        float sum = 0.0f;
        for (unsigned tile = lane; tile < blockIdx.x; tile += kWarp) {
            sum += output[tile];
        }
        sum = warp_sum(sum);
        if (lane == 0) tile_offset = sum;
    }
    grid.sync();

    const float prefix = local_prefix + tile_offset;
    float4* dest = reinterpret_cast<float4*>(output);
    dest[group * 2] = make_float4(group == 0 ? a0 : a0 + prefix,
                                  a1 + prefix, a2 + prefix, a3 + prefix);
    dest[group * 2 + 1] = make_float4(b0 + prefix, b1 + prefix, b2 + prefix, b3 + prefix);
}

bool launch_cooperative(const float* input, float* output, size_t count) {
    cudaStreamCaptureStatus capture = cudaStreamCaptureStatusNone;
    if (cudaStreamIsCapturing(nullptr, &capture) != cudaSuccess ||
        capture != cudaStreamCaptureStatusNone) return false;

    int device = 0;
    if (cudaGetDevice(&device) != cudaSuccess) return false;
    thread_local int cached_device = -1;
    thread_local int largest_grid = 0;
    if (device != cached_device) {
        int supported = 0, sm_count = 0, active_blocks = 0;
        cached_device = device;
        largest_grid = 0;
        if (cudaDeviceGetAttribute(&supported, cudaDevAttrCooperativeLaunch, device) != cudaSuccess ||
            supported == 0 ||
            cudaDeviceGetAttribute(&sm_count, cudaDevAttrMultiProcessorCount, device) != cudaSuccess ||
            cudaOccupancyMaxActiveBlocksPerMultiprocessor(&active_blocks, scan_cooperative, kThreads, 0) != cudaSuccess) {
            return false;
        }
        largest_grid = sm_count * active_blocks;
    }
    if (count > static_cast<unsigned>(largest_grid)) return false;

    void* args[] = {&input, &output};
    const cudaError_t launch = cudaLaunchCooperativeKernel(
        reinterpret_cast<const void*>(scan_cooperative), dim3(static_cast<unsigned>(count)),
        dim3(kThreads), args, 0, nullptr);
    if (launch != cudaSuccess) {
        cudaGetLastError();
        return false;
    }
    return true;
}

}  // namespace

extern "C" void solution(const float* input, float* output, size_t N) {
    if (N == 0) return;
    const auto blocks = static_cast<unsigned>(1 + (N - 1) / kTile);
    const bool vector = N % kTile == 0 &&
        (reinterpret_cast<uintptr_t>(input) | reinterpret_cast<uintptr_t>(output)) % alignof(float4) == 0;
    if (vector && input != output && N % kCoopTile == 0 &&
        launch_cooperative(input, output, N / kCoopTile)) return;

    if (vector) scan_tiles<true><<<blocks, kThreads>>>(input, output, N);
    else scan_tiles<false><<<blocks, kThreads>>>(input, output, N);

    if (blocks > 1) {
        scan_tile_ends(output, N, blocks, kTile);
        if (vector) add_to_tiles<true><<<blocks - 1, kThreads>>>(output, N);
        else add_to_tiles<false><<<blocks - 1, kThreads>>>(output, N);
    }
}
