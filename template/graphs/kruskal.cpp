/*
 * Kruskal 最小生成树算法
 * 用途：求无向图的最小生成树（MST）
 * 时间复杂度：O(E log E) 主要是排序的时间
 * 空间复杂度：O(V + E)
 * 适用：稀疏图
 */

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    long long weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// 并查集（用于检测环）
class UnionFind {
private:
    vector<int> parent, rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return false;

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};

class Graph {
private:
    int V;
    vector<Edge> edges;

public:
    Graph(int vertices) : V(vertices) {}

    void addEdge(int u, int v, long long weight) {
        edges.push_back({u, v, weight});
    }

    // Kruskal算法求最小生成树
    pair<long long, vector<Edge>> kruskal() {
        // 按权重排序所有边
        sort(edges.begin(), edges.end());

        UnionFind uf(V);
        vector<Edge> mst;
        long long totalWeight = 0;

        for (const Edge& edge : edges) {
            // 如果添加这条边不会形成环
            if (uf.unite(edge.u, edge.v)) {
                mst.push_back(edge);
                totalWeight += edge.weight;

                // MST有V-1条边
                if (mst.size() == V - 1) {
                    break;
                }
            }
        }

        return {totalWeight, mst};
    }

    // 求最大生成树（只需将边按降序排列）
    pair<long long, vector<Edge>> maximumSpanningTree() {
        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.weight > b.weight;
        });

        UnionFind uf(V);
        vector<Edge> mst;
        long long totalWeight = 0;

        for (const Edge& edge : edges) {
            if (uf.unite(edge.u, edge.v)) {
                mst.push_back(edge);
                totalWeight += edge.weight;
                if (mst.size() == V - 1) break;
            }
        }

        return {totalWeight, mst};
    }

    // 求第k小的生成树（返回所有可能的生成树）
    vector<pair<long long, vector<Edge>>> allSpanningTrees() {
        sort(edges.begin(), edges.end());
        vector<pair<long long, vector<Edge>>> result;

        function<void(int, UnionFind&, vector<Edge>&, long long)> backtrack =
            [&](int idx, UnionFind& uf, vector<Edge>& current, long long weight) {
                if (current.size() == V - 1) {
                    result.push_back({weight, current});
                    return;
                }

                if (idx >= edges.size()) return;

                // 尝试添加当前边
                if (uf.unite(edges[idx].u, edges[idx].v)) {
                    current.push_back(edges[idx]);
                    backtrack(idx + 1, uf, current, weight + edges[idx].weight);
                    current.pop_back();
                }

                // 不添加当前边
                backtrack(idx + 1, uf, current, weight);
            };

        UnionFind uf(V);
        vector<Edge> current;
        backtrack(0, uf, current, 0);

        return result;
    }
};

// Prim算法（作为对比）
class PrimMST {
private:
    int V;
    vector<vector<pair<int, long long>>> adj;  // {neighbor, weight}

public:
    PrimMST(int vertices) : V(vertices) {
        adj.resize(V);
    }

    void addEdge(int u, int v, long long weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    pair<long long, vector<pair<int, int>>> prim() {
        const long long INF = 1e18;
        vector<long long> key(V, INF);
        vector<int> parent(V, -1);
        vector<bool> inMST(V, false);

        priority_queue<pair<long long, int>,
                      vector<pair<long long, int>>,
                      greater<pair<long long, int>>> pq;

        key[0] = 0;
        pq.push({0, 0});

        long long totalWeight = 0;
        vector<pair<int, int>> mstEdges;

        while (!pq.empty()) {
            auto [w, u] = pq.top();
            pq.pop();

            if (inMST[u]) continue;

            inMST[u] = true;
            totalWeight += w;

            if (parent[u] != -1) {
                mstEdges.push_back({parent[u], u});
            }

            for (auto [v, weight] : adj[u]) {
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                    pq.push({weight, v});
                }
            }
        }

        return {totalWeight, mstEdges};
    }
};

// 使用示例
int main() {
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    // Kruskal算法
    auto [weight, mst] = g.kruskal();
    cout << "Kruskal MST weight: " << weight << endl;
    cout << "MST edges:" << endl;
    for (const Edge& e : mst) {
        cout << e.u << " - " << e.v << " : " << e.weight << endl;
    }

    // Prim算法
    PrimMST pg(4);
    pg.addEdge(0, 1, 10);
    pg.addEdge(0, 2, 6);
    pg.addEdge(0, 3, 5);
    pg.addEdge(1, 3, 15);
    pg.addEdge(2, 3, 4);

    auto [weight2, mstEdges] = pg.prim();
    cout << "\nPrim MST weight: " << weight2 << endl;
    cout << "MST edges:" << endl;
    for (auto [u, v] : mstEdges) {
        cout << u << " - " << v << endl;
    }

    return 0;
}
