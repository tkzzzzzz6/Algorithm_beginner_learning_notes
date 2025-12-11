/*
 * Dijkstra 最短路径算法
 * 用途：单源最短路径（非负权边）
 * 时间复杂度：O((V + E) log V) 使用优先队列
 * 空间复杂度：O(V + E)
 * 注意：不能处理负权边
 */

#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

class Graph {
private:
    int V;
    vector<vector<pair<int, long long>>> adj;  // {neighbor, weight}

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }

    void addEdge(int u, int v, long long weight, bool directed = false) {
        adj[u].push_back({v, weight});
        if (!directed) {
            adj[v].push_back({u, weight});
        }
    }

    // Dijkstra算法（返回从start到所有节点的最短距离）
    vector<long long> dijkstra(int start) {
        vector<long long> dist(V, INF);
        priority_queue<pair<long long, int>,
                      vector<pair<long long, int>>,
                      greater<pair<long long, int>>> pq;

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (auto [v, weight] : adj[u]) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }

    // Dijkstra算法（返回最短路径）
    pair<vector<long long>, vector<int>> dijkstraWithPath(int start) {
        vector<long long> dist(V, INF);
        vector<int> parent(V, -1);
        priority_queue<pair<long long, int>,
                      vector<pair<long long, int>>,
                      greater<pair<long long, int>>> pq;

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (auto [v, weight] : adj[u]) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }

        return {dist, parent};
    }

    // 重构从start到end的最短路径
    vector<int> getPath(int start, int end) {
        auto [dist, parent] = dijkstraWithPath(start);

        if (dist[end] == INF) return {};  // 无法到达

        vector<int> path;
        for (int v = end; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
        return path;
    }
};

// 使用示例
int main() {
    Graph g(6);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 8);
    g.addEdge(2, 4, 10);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 5, 6);
    g.addEdge(4, 5, 3);

    int start = 0;
    vector<long long> dist = g.dijkstra(start);

    cout << "Shortest distances from node " << start << ":" << endl;
    for (int i = 0; i < dist.size(); i++) {
        if (dist[i] == INF) {
            cout << "To " << i << ": INF" << endl;
        } else {
            cout << "To " << i << ": " << dist[i] << endl;
        }
    }

    // 获取路径
    vector<int> path = g.getPath(0, 5);
    cout << "\nShortest path from 0 to 5: ";
    for (int v : path) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
