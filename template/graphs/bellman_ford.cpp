/*
 * Bellman-Ford 最短路径算法
 * 用途：单源最短路径（可处理负权边，检测负环）
 * 时间复杂度：O(VE)
 * 空间复杂度：O(V)
 * 优点：可以处理负权边，可以检测负环
 */

#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

struct Edge {
    int from, to;
    long long weight;
};

class Graph {
private:
    int V;
    vector<Edge> edges;

public:
    Graph(int vertices) : V(vertices) {}

    void addEdge(int u, int v, long long weight, bool directed = false) {
        edges.push_back({u, v, weight});
        if (!directed) {
            edges.push_back({v, u, weight});
        }
    }

    // Bellman-Ford算法
    pair<vector<long long>, bool> bellmanFord(int start) {
        vector<long long> dist(V, INF);
        dist[start] = 0;

        // 松弛操作 V-1 次
        for (int i = 0; i < V - 1; i++) {
            for (const auto& edge : edges) {
                if (dist[edge.from] != INF &&
                    dist[edge.from] + edge.weight < dist[edge.to]) {
                    dist[edge.to] = dist[edge.from] + edge.weight;
                }
            }
        }

        // 检测负环
        for (const auto& edge : edges) {
            if (dist[edge.from] != INF &&
                dist[edge.from] + edge.weight < dist[edge.to]) {
                return {dist, true};  // 存在负环
            }
        }

        return {dist, false};  // 不存在负环
    }

    // 带路径重构的Bellman-Ford
    pair<vector<long long>, vector<int>> bellmanFordWithPath(int start) {
        vector<long long> dist(V, INF);
        vector<int> parent(V, -1);
        dist[start] = 0;

        for (int i = 0; i < V - 1; i++) {
            for (const auto& edge : edges) {
                if (dist[edge.from] != INF &&
                    dist[edge.from] + edge.weight < dist[edge.to]) {
                    dist[edge.to] = dist[edge.from] + edge.weight;
                    parent[edge.to] = edge.from;
                }
            }
        }

        return {dist, parent};
    }

    // 获取从start到end的路径
    vector<int> getPath(int start, int end) {
        auto [dist, parent] = bellmanFordWithPath(start);

        if (dist[end] == INF) return {};

        vector<int> path;
        for (int v = end; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
        return path;
    }

    // SPFA优化（队列优化的Bellman-Ford）
    pair<vector<long long>, bool> spfa(int start) {
        vector<long long> dist(V, INF);
        vector<int> cnt(V, 0);  // 记录每个点入队次数
        vector<bool> inQueue(V, false);
        queue<int> q;

        dist[start] = 0;
        q.push(start);
        inQueue[start] = true;
        cnt[start]++;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inQueue[u] = false;

            for (const auto& edge : edges) {
                if (edge.from == u && dist[u] != INF &&
                    dist[u] + edge.weight < dist[edge.to]) {
                    dist[edge.to] = dist[u] + edge.weight;

                    if (!inQueue[edge.to]) {
                        q.push(edge.to);
                        inQueue[edge.to] = true;
                        cnt[edge.to]++;

                        // 如果某个点入队超过V次，存在负环
                        if (cnt[edge.to] >= V) {
                            return {dist, true};
                        }
                    }
                }
            }
        }

        return {dist, false};
    }
};

// 使用示例
int main() {
    Graph g(5);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, -3);  // 负权边
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 4);
    g.addEdge(3, 4, 1);

    int start = 0;
    auto [dist, hasNegativeCycle] = g.bellmanFord(start);

    if (hasNegativeCycle) {
        cout << "Graph contains negative cycle!" << endl;
    } else {
        cout << "Shortest distances from node " << start << ":" << endl;
        for (int i = 0; i < dist.size(); i++) {
            if (dist[i] == INF) {
                cout << "To " << i << ": INF" << endl;
            } else {
                cout << "To " << i << ": " << dist[i] << endl;
            }
        }
    }

    // 使用SPFA
    auto [dist2, hasNegCycle] = g.spfa(start);
    cout << "\nSPFA results:" << endl;
    if (!hasNegCycle) {
        for (int i = 0; i < dist2.size(); i++) {
            if (dist2[i] != INF) {
                cout << "To " << i << ": " << dist2[i] << endl;
            }
        }
    }

    return 0;
}
