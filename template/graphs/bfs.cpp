/*
 * 广度优先搜索 (Breadth-First Search - BFS)
 * 用途：无权图最短路径、层次遍历、最少步数问题
 * 时间复杂度：O(V + E)
 * 空间复杂度：O(V)
 */

#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }

    void addEdge(int u, int v, bool directed = false) {
        adj[u].push_back(v);
        if (!directed) {
            adj[v].push_back(u);
        }
    }

    // BFS遍历（从指定节点开始）
    vector<int> bfs(int start) {
        vector<bool> visited(V, false);
        vector<int> result;
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            result.push_back(v);

            for (int u : adj[v]) {
                if (!visited[u]) {
                    visited[u] = true;
                    q.push(u);
                }
            }
        }
        return result;
    }

    // 计算从start到所有节点的最短距离
    vector<int> shortestPath(int start) {
        vector<int> dist(V, -1);
        queue<int> q;

        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int u : adj[v]) {
                if (dist[u] == -1) {
                    dist[u] = dist[v] + 1;
                    q.push(u);
                }
            }
        }
        return dist;
    }

    // 找从start到end的最短路径
    vector<int> findPath(int start, int end) {
        vector<int> parent(V, -1);
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            if (v == end) break;

            for (int u : adj[v]) {
                if (!visited[u]) {
                    visited[u] = true;
                    parent[u] = v;
                    q.push(u);
                }
            }
        }

        // 重构路径
        vector<int> path;
        if (parent[end] != -1 || start == end) {
            for (int v = end; v != -1; v = parent[v]) {
                path.push_back(v);
            }
            reverse(path.begin(), path.end());
        }
        return path;
    }

    // BFS层次遍历
    vector<vector<int>> bfsLevels(int start) {
        vector<vector<int>> levels;
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                int v = q.front();
                q.pop();
                level.push_back(v);

                for (int u : adj[v]) {
                    if (!visited[u]) {
                        visited[u] = true;
                        q.push(u);
                    }
                }
            }
            levels.push_back(level);
        }
        return levels;
    }
};

// 使用示例
int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    // BFS遍历
    vector<int> result = g.bfs(0);
    cout << "BFS traversal from node 0: ";
    for (int v : result) {
        cout << v << " ";
    }
    cout << endl;

    // 最短距离
    vector<int> dist = g.shortestPath(0);
    cout << "Shortest distances from node 0:" << endl;
    for (int i = 0; i < dist.size(); i++) {
        cout << "To " << i << ": " << dist[i] << endl;
    }

    // 最短路径
    vector<int> path = g.findPath(0, 5);
    cout << "Shortest path from 0 to 5: ";
    for (int v : path) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
