#include <cuda_runtime.h>
#include <stddef.h>

namespace {

using EdgeKey = unsigned long long;
constexpr EdgeKey kNoEdge = ~EdgeKey{0};
constexpr unsigned kThreads = 256;
constexpr unsigned kWarpSize = 32;
constexpr unsigned kWarps = kThreads / kWarpSize;
constexpr unsigned kMaxPackedVertices = 65536;
constexpr unsigned kMaxSharedVertices = 8192;

struct State {
    double weight;
    unsigned components;
    bool running;
};

__device__ __forceinline__ EdgeKey edge_key(float weight, unsigned index) {
    return (static_cast<EdgeKey>(__float_as_uint(weight)) << 32) | index;
}

__device__ __forceinline__ float edge_weight(EdgeKey key) {
    return __uint_as_float(static_cast<unsigned>(key >> 32));
}

__device__ __forceinline__ EdgeKey warp_min(EdgeKey value) {
    for (int offset = kWarpSize / 2; offset > 0; offset /= 2) {
        const EdgeKey other = __shfl_down_sync(0xffffffffu, value, offset);
        value = other < value ? other : value;
    }
    return value;
}

__device__ __forceinline__ EdgeKey block_min(EdgeKey value, EdgeKey* warp_minima) {
    const unsigned lane = threadIdx.x % kWarpSize;
    value = warp_min(value);
    if (lane == 0) warp_minima[threadIdx.x / kWarpSize] = value;
    __syncthreads();
    if (threadIdx.x < kWarpSize) {
        value = warp_min(threadIdx.x < kWarps ? warp_minima[threadIdx.x] : kNoEdge);
    }
    return value;
}

__device__ __forceinline__ unsigned root_of(const unsigned* parents, unsigned vertex) {
    while (parents[vertex] != vertex) vertex = parents[vertex];
    return vertex;
}

__global__ void initialize(EdgeKey* outgoing, unsigned* labels, State* state, unsigned n) {
    const unsigned i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i < n) {
        outgoing[i] = kNoEdge;
        labels[i] = i;
    }
    if (i == 0) *state = {0.0, n, true};
}

__global__ void find_outgoing_edges(const float* adjacency, EdgeKey* outgoing,
                                    const unsigned* labels, const State* state, unsigned n) {
    if (!state->running) return;

    __shared__ EdgeKey warp_minima[kWarps];
    const unsigned u = blockIdx.x;
    const unsigned label = labels[u];
    const float* row = adjacency + static_cast<size_t>(u) * n;
    EdgeKey best = kNoEdge;
    for (unsigned v = threadIdx.x; v < n; v += kThreads) {
        const float weight = row[v];
        if (weight > 0.0f && labels[v] != label) {
            const EdgeKey candidate = edge_key(weight, v);
            best = candidate < best ? candidate : best;
        }
    }
    best = block_min(best, warp_minima);
    if (threadIdx.x == 0 && best != kNoEdge) {
        const unsigned v = static_cast<unsigned>(best);
        // The canonical edge index gives all components the same tie order.
        // For fixed u, ordering the canonical indices is equivalent to ordering v.
        const unsigned index = u < v ? u * n + v : v * n + u;
        atomicMin(&outgoing[label], edge_key(edge_weight(best), index));
    }
}

__global__ void merge_components(EdgeKey* outgoing, unsigned* labels, unsigned* global_parents,
                                 State* state, unsigned n) {
    if (!state->running) return;

    extern __shared__ unsigned shared_parents[];
    __shared__ EdgeKey candidates[kThreads];
    unsigned* parents = n <= kMaxSharedVertices ? shared_parents : global_parents;
    for (unsigned i = threadIdx.x; i < n; i += kThreads) parents[i] = labels[i];
    __syncthreads();

    double total = state->weight;
    unsigned merged = 0;
    for (unsigned start = 0; start < n; start += kThreads) {
        const unsigned i = start + threadIdx.x;
        candidates[threadIdx.x] = i < n ? outgoing[i] : kNoEdge;
        if (i < n) outgoing[i] = kNoEdge;
        __syncthreads();

        if (threadIdx.x == 0) {
            for (unsigned j = 0; j < kThreads; ++j) {
                const EdgeKey key = candidates[j];
                if (key == kNoEdge) continue;
                const unsigned edge = static_cast<unsigned>(key);
                const unsigned u = root_of(parents, edge / n);
                const unsigned v = root_of(parents, edge % n);
                if (u != v) {
                    parents[u > v ? u : v] = u < v ? u : v;
                    total += edge_weight(key);
                    ++merged;
                }
            }
        }
        __syncthreads();
    }

    for (unsigned i = threadIdx.x; i < n; i += kThreads) labels[i] = root_of(parents, i);
    if (threadIdx.x == 0) {
        state->weight = total;
        state->components -= merged;
        state->running = merged > 0 && state->components > 1;
    }
}

__global__ void finish(const State* state, float* result) {
    *result = state == nullptr ? 0.0f
        : state->components == 1 ? static_cast<float>(state->weight) : -1.0f;
}

// Prim's algorithm handles graphs whose canonical edge indices exceed 32 bits.
__global__ void prim_large_graph(const float* adjacency, float* distance,
                                 float* result, unsigned n) {
    __shared__ EdgeKey warp_minima[kWarps];
    __shared__ unsigned vertex;
    for (unsigned i = threadIdx.x; i < n; i += kThreads) {
        distance[i] = i == 0 ? 0.0f : __int_as_float(0x7f800000);
    }
    if (threadIdx.x == 0) vertex = 0;
    __syncthreads();
    double total = 0.0;
    for (unsigned step = 1; step < n; ++step) {
        const float* row = adjacency + static_cast<size_t>(vertex) * n;
        EdgeKey best = kNoEdge;
        for (unsigned i = threadIdx.x; i < n; i += kThreads) {
            float current = distance[i];
            if (current == 0.0f) continue;
            const float weight = row[i];
            if (weight > 0.0f && weight < current) {
                current = weight;
                distance[i] = current;
            }
            if (__float_as_uint(current) != 0x7f800000u) {
                const EdgeKey candidate = edge_key(current, i);
                best = candidate < best ? candidate : best;
            }
        }
        best = block_min(best, warp_minima);
        if (threadIdx.x == 0) {
            vertex = best == kNoEdge ? n : static_cast<unsigned>(best);
            if (vertex == n) *result = -1.0f;
            else {
                distance[vertex] = 0.0f;
                total += edge_weight(best);
            }
        }
        __syncthreads();
        if (vertex == n) return;
    }
    if (threadIdx.x == 0) *result = static_cast<float>(total);
}

}  // namespace

extern "C" void solution(const float* A, float* min_weight, size_t n) {
    if (n <= 1) {
        finish<<<1, 1>>>(nullptr, min_weight);
        return;
    }

    const bool packed = n <= kMaxPackedVertices;
    const size_t bytes = packed
        ? sizeof(State) + n * (sizeof(EdgeKey) + 2 * sizeof(unsigned))
        : n * sizeof(float);
    void* scratch = nullptr;
    const bool async = cudaMallocAsync(&scratch, bytes, nullptr) == cudaSuccess;
    if (!async) {
        cudaGetLastError();
        if (cudaMalloc(&scratch, bytes) != cudaSuccess) return;
    }

    const auto vertices = static_cast<unsigned>(n);
    if (packed) {
        auto* state = static_cast<State*>(scratch);
        auto* outgoing = reinterpret_cast<EdgeKey*>(state + 1);
        auto* labels = reinterpret_cast<unsigned*>(outgoing + n);
        auto* parents = labels + n;
        const size_t shared_bytes = n <= kMaxSharedVertices ? n * sizeof(unsigned) : 0;
        initialize<<<(vertices + kThreads - 1) / kThreads, kThreads>>>(outgoing, labels, state, vertices);
        // Every non-isolated component merges with at least one other component per round.
        for (unsigned span = 1; span < vertices; span *= 2) {
            find_outgoing_edges<<<vertices, kThreads>>>(A, outgoing, labels, state, vertices);
            merge_components<<<1, kThreads, shared_bytes>>>(outgoing, labels, parents, state, vertices);
        }
        finish<<<1, 1>>>(state, min_weight);
    } else {
        prim_large_graph<<<1, kThreads>>>(A, static_cast<float*>(scratch), min_weight, vertices);
    }

    if (async) cudaFreeAsync(scratch, nullptr);
    else cudaFree(scratch);
}
