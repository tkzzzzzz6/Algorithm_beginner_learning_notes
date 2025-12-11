/*
 * 强连通分量 (Strongly Connected Components - SCC)
 * 用途：有向图的分解、找环、图的缩点
 * Kosaraju算法时间复杂度：O(V + E)
 * Tarjan算法时间复杂度：O(V + E)
 * 空间复杂度：O(V)
 */

#include <bits/stdc++.h>
using namespace std;

// Kosaraju算法实现
class KosarajuSCC {
private:
    int V;
    vector<vector<int>> adj, revAdj;

    void dfs1(int v, vector<bool>& visited, stack<int>& stk) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u]) {
                dfs1(u, visited, stk);
            }
        }
        stk.push(v);
    }

    void dfs2(int v, vector<bool>& visited, vector<int>& component) {
        visited[v] = true;
        component.push_back(v);
        for (int u : revAdj[v]) {
            if (!visited[u]) {
                dfs2(u, visited, component);
            }
        }
    }

public:
    KosarajuSCC(int vertices) : V(vertices) {
        adj.resize(V);
        revAdj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        revAdj[v].push_back(u);  // 反向边
    }

    vector<vector<int>> findSCCs() {
        stack<int> stk;
        vector<bool> visited(V, false);

        // 第一次DFS，按完成时间排序
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs1(i, visited, stk);
            }
        }

        // 第二次DFS，在反向图上找强连通分量
        fill(visited.begin(), visited.end(), false);
        vector<vector<int>> sccs;

        while (!stk.empty()) {
            int v = stk.top();
            stk.pop();

            if (!visited[v]) {
                vector<int> component;
                dfs2(v, visited, component);
                sccs.push_back(component);
            }
        }

        return sccs;
    }
};

// Tarjan算法实现
class TarjanSCC {
private:
    int V;
    vector<vector<int>> adj;
    vector<int> low, disc, stackMember;
    stack<int> stk;
    int timer;
    vector<vector<int>> sccs;

    void tarjanUtil(int u) {
        disc[u] = low[u] = timer++;
        stk.push(u);
        stackMember[u] = 1;

        for (int v : adj[u]) {
            if (disc[v] == -1) {
                tarjanUtil(v);
                low[u] = min(low[u], low[v]);
            } else if (stackMember[v]) {
                low[u] = min(low[u], disc[v]);
            }
        }

        // u是SCC的根节点
        if (low[u] == disc[u]) {
            vector<int> component;
            while (true) {
                int v = stk.top();
                stk.pop();
                stackMember[v] = 0;
                component.push_back(v);
                if (v == u) break;
            }
            sccs.push_back(component);
        }
    }

public:
    TarjanSCC(int vertices) : V(vertices), timer(0) {
        adj.resize(V);
        low.assign(V, -1);
        disc.assign(V, -1);
        stackMember.assign(V, 0);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    vector<vector<int>> findSCCs() {
        sccs.clear();
        for (int i = 0; i < V; i++) {
            if (disc[i] == -1) {
                tarjanUtil(i);
            }
        }
        return sccs;
    }
};

// 缩点：将强连通分量缩成一个点
class SCCGraph {
private:
    int V;
    vector<vector<int>> adj;

public:
    SCCGraph(int vertices) : V(vertices) {
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // 返回缩点后的DAG和每个节点所属的SCC编号
    pair<vector<vector<int>>, vector<int>> buildCondensationGraph() {
        TarjanSCC tarjan(V);
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                tarjan.addEdge(u, v);
            }
        }

        vector<vector<int>> sccs = tarjan.findSCCs();
        int numSCC = sccs.size();

        // 记录每个节点属于哪个SCC
        vector<int> sccId(V);
        for (int i = 0; i < numSCC; i++) {
            for (int v : sccs[i]) {
                sccId[v] = i;
            }
        }

        // 构建缩点后的DAG
        set<pair<int, int>> edges;
        vector<vector<int>> dag(numSCC);

        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                if (sccId[u] != sccId[v]) {
                    if (edges.find({sccId[u], sccId[v]}) == edges.end()) {
                        edges.insert({sccId[u], sccId[v]});
                        dag[sccId[u]].push_back(sccId[v]);
                    }
                }
            }
        }

        return {dag, sccId};
    }
};

// 使用示例
int main() {
    // Kosaraju算法示例
    cout << "Kosaraju Algorithm:" << endl;
    KosarajuSCC g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);

    vector<vector<int>> sccs1 = g1.findSCCs();
    cout << "Number of SCCs: " << sccs1.size() << endl;
    for (int i = 0; i < sccs1.size(); i++) {
        cout << "SCC " << i << ": ";
        for (int v : sccs1[i]) {
            cout << v << " ";
        }
        cout << endl;
    }

    // Tarjan算法示例
    cout << "\nTarjan Algorithm:" << endl;
    TarjanSCC g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);

    vector<vector<int>> sccs2 = g2.findSCCs();
    cout << "Number of SCCs: " << sccs2.size() << endl;
    for (int i = 0; i < sccs2.size(); i++) {
        cout << "SCC " << i << ": ";
        for (int v : sccs2[i]) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
