/*
 * 深度优先搜索 (Depth-First Search - DFS)
 * 用途：图的遍历、寻找路径、检测环、连通性判断
 * 时间复杂度：O(V + E)
 * 空间复杂度：O(V)
 */

#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;
    vector<bool> visited;

    void dfsUtil(int v, vector<int>& result) {
        visited[v] = true;
        result.push_back(v);

        for (int u : adj[v]) {
            if (!visited[u]) {
                dfsUtil(u, result);
            }
        }
    }

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
        visited.resize(V, false);
    }

    void addEdge(int u, int v, bool directed = false) {
        adj[u].push_back(v);
        if (!directed) {
            adj[v].push_back(u);
        }
    }

    // DFS遍历（从指定节点开始）
    vector<int> dfs(int start) {
        fill(visited.begin(), visited.end(), false);
        vector<int> result;
        dfsUtil(start, result);
        return result;
    }

    // DFS遍历所有连通分量
    vector<vector<int>> dfsAll() {
        fill(visited.begin(), visited.end(), false);
        vector<vector<int>> components;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                vector<int> component;
                dfsUtil(i, component);
                components.push_back(component);
            }
        }
        return components;
    }

    // 判断是否存在从u到v的路径
    bool hasPath(int u, int v) {
        fill(visited.begin(), visited.end(), false);
        return hasPathUtil(u, v);
    }

private:
    bool hasPathUtil(int u, int v) {
        if (u == v) return true;
        visited[u] = true;

        for (int next : adj[u]) {
            if (!visited[next] && hasPathUtil(next, v)) {
                return true;
            }
        }
        return false;
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

    // 从节点0开始DFS
    vector<int> result = g.dfs(0);
    cout << "DFS traversal from node 0: ";
    for (int v : result) {
        cout << v << " ";
    }
    cout << endl;

    // 检查路径
    cout << "Path from 0 to 5 exists: " << g.hasPath(0, 5) << endl;

    return 0;
}
