/*
 * 拓扑排序 (Topological Sort)
 * 用途：有向无环图(DAG)的顶点排序、任务调度、依赖关系处理
 * 时间复杂度：O(V + E)
 * 空间复杂度：O(V)
 * 注意：只适用于有向无环图
 */

#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;

    // DFS方法实现拓扑排序
    void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& stk) {
        visited[v] = true;

        for (int u : adj[v]) {
            if (!visited[u]) {
                topologicalSortUtil(u, visited, stk);
            }
        }

        stk.push(v);
    }

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);  // 有向边
    }

    // 方法1：DFS实现拓扑排序
    vector<int> topologicalSortDFS() {
        stack<int> stk;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                topologicalSortUtil(i, visited, stk);
            }
        }

        vector<int> result;
        while (!stk.empty()) {
            result.push_back(stk.top());
            stk.pop();
        }
        return result;
    }

    // 方法2：Kahn算法（BFS）实现拓扑排序
    pair<vector<int>, bool> topologicalSortKahn() {
        vector<int> inDegree(V, 0);

        // 计算每个节点的入度
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                inDegree[v]++;
            }
        }

        // 将所有入度为0的节点加入队列
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;
        int count = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(u);
            count++;

            // 将u的所有邻接节点的入度减1
            for (int v : adj[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // 如果count != V，说明存在环
        bool hasNoCycle = (count == V);
        return {result, hasNoCycle};
    }

    // 检测是否有环（DFS方法）
    bool hasCycle() {
        vector<int> state(V, 0);  // 0: 未访问, 1: 访问中, 2: 已完成

        function<bool(int)> dfs = [&](int u) -> bool {
            state[u] = 1;
            for (int v : adj[u]) {
                if (state[v] == 1) return true;  // 发现环
                if (state[v] == 0 && dfs(v)) return true;
            }
            state[u] = 2;
            return false;
        };

        for (int i = 0; i < V; i++) {
            if (state[i] == 0 && dfs(i)) {
                return true;
            }
        }
        return false;
    }

    // 所有可能的拓扑排序
    void allTopologicalSortsUtil(vector<bool>& visited, vector<int>& inDegree,
                                 vector<int>& path, vector<vector<int>>& result) {
        bool flag = false;

        for (int i = 0; i < V; i++) {
            if (!visited[i] && inDegree[i] == 0) {
                visited[i] = true;
                path.push_back(i);

                for (int v : adj[i]) {
                    inDegree[v]--;
                }

                allTopologicalSortsUtil(visited, inDegree, path, result);

                // 回溯
                visited[i] = false;
                path.pop_back();
                for (int v : adj[i]) {
                    inDegree[v]++;
                }

                flag = true;
            }
        }

        if (!flag) {
            result.push_back(path);
        }
    }

    vector<vector<int>> allTopologicalSorts() {
        vector<bool> visited(V, false);
        vector<int> inDegree(V, 0);
        vector<int> path;
        vector<vector<int>> result;

        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                inDegree[v]++;
            }
        }

        allTopologicalSortsUtil(visited, inDegree, path, result);
        return result;
    }
};

// 使用示例
int main() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    // DFS方法
    cout << "Topological Sort (DFS): ";
    vector<int> result1 = g.topologicalSortDFS();
    for (int v : result1) {
        cout << v << " ";
    }
    cout << endl;

    // Kahn算法
    auto [result2, hasNoCycle] = g.topologicalSortKahn();
    if (hasNoCycle) {
        cout << "Topological Sort (Kahn): ";
        for (int v : result2) {
            cout << v << " ";
        }
        cout << endl;
    } else {
        cout << "Graph has a cycle!" << endl;
    }

    // 检测环
    cout << "Has cycle: " << (g.hasCycle() ? "Yes" : "No") << endl;

    return 0;
}
