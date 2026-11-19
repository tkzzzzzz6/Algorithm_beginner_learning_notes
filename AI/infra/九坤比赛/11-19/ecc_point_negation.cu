#include <cuda_runtime.h>
#include <stddef.h>
#include <stdint.h>

namespace {

constexpr unsigned kThreads = 256;
constexpr unsigned kPoints = 2;

template <bool Full>
__global__ void negate_striped(const uint64_t* __restrict__ xs,
                               const uint64_t* __restrict__ ys,
                               uint64_t p, ulonglong2* __restrict__ out,
                               size_t n) {
    const size_t start = static_cast<size_t>(blockIdx.x) * (kThreads * kPoints)
                       + threadIdx.x;
    uint64_t xs_local[kPoints], ys_local[kPoints];
    #pragma unroll
    for (unsigned k = 0; k < kPoints; ++k) {
        const size_t i = start + k * kThreads;
        if (Full || i < n) {
            xs_local[k] = xs[i];
            ys_local[k] = ys[i];
        }
    }
    #pragma unroll
    for (unsigned k = 0; k < kPoints; ++k) {
        const size_t i = start + k * kThreads;
        if (Full || i < n) {
            const uint64_t y = ys_local[k];
            out[i] = make_ulonglong2(xs_local[k], y == 0 ? 0 : p - y);
        }
    }
}

__global__ void negate_scalar(const uint64_t* xs, const uint64_t* ys,
                              uint64_t p, uint64_t* out, size_t n) {
    const size_t i = static_cast<size_t>(blockIdx.x) * kThreads + threadIdx.x;
    if (i < n) {
        const uint64_t y = ys[i];
        out[2 * i] = xs[i];
        out[2 * i + 1] = y == 0 ? 0 : p - y;
    }
}

}  // namespace

extern "C" void solution(const uint64_t* xs, const uint64_t* ys,
                         const uint64_t p, uint64_t* out_xy, size_t n) {
    if (n == 0) return;

    if (reinterpret_cast<uintptr_t>(out_xy) % alignof(ulonglong2) != 0) {
        const auto blocks = static_cast<unsigned>(1 + (n - 1) / kThreads);
        negate_scalar<<<blocks, kThreads>>>(xs, ys, p, out_xy, n);
        return;
    }

    constexpr unsigned kTile = kThreads * kPoints;
    const auto blocks = static_cast<unsigned>(1 + (n - 1) / kTile);
    auto* out = reinterpret_cast<ulonglong2*>(out_xy);
    if (n % kTile == 0) {
        negate_striped<true><<<blocks, kThreads>>>(xs, ys, p, out, n);
    } else {
        negate_striped<false><<<blocks, kThreads>>>(xs, ys, p, out, n);
    }
}
