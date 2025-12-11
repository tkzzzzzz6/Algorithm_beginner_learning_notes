/*
 * Floyd-Warshall 全源最短路径算法
 * 用途：计算所有节点对之间的最短路径
 * 时间复杂度：O(V^3)
 * 空间复杂度：O(V^2)
 * 优点：可以处理负权边，可以检测负环，适合稠密图
 */

#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

class Graph {
private:
    int V;
    vector<vector<long long>> dist;
    vector<vector<int>> next;  // 用于路径重构

public:
    Graph(int vertices) : V(vertices) {
        dist.assign(V, vector<long long>(V, INF));
        next.assign(V, vector<int>(V, -1));

        // 初始化对角线为0
        for (int i = 0; i < V; i++) {
            dist[i][i] = 0;
        }
    }

    void addEdge(int u, int v, long long weight, bool directed = false) {
        dist[u][v] = weight;
        next[u][v] = v;
        if (!directed) {
            dist[v][u] = weight;
            next[v][u] = u;
        }
    }

    // Floyd-Warshall算法
    bool floydWarshall() {
        // 动态规划求最短路径
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF &&
                        dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        next[i][j] = next[i][k];
                    }
                }
            }
        }

        // 检测负环
        for (int i = 0; i < V; i++) {
            if (dist[i][i] < 0) {
                return false;  // 存在负环
            }
        }
        return true;  // 不存在负环
    }

    // 获取从u到v的最短距离
    long long getDistance(int u, int v) {
        return dist[u][v];
    }

    // 重构从u到v的最短路径
    vector<int> getPath(int u, int v) {
        if (dist[u][v] == INF) return {};

        vector<int> path;
        int curr = u;
        path.push_back(curr);

        while (curr != v) {
            curr = next[curr][v];
            if (curr == -1) return {};  // 无路径
            path.push_back(curr);
        }

        return path;
    }

    // 打印距离矩阵
    void printDistances() {
        cout << "Distance matrix:" << endl;
        cout << "    ";
        for (int i = 0; i < V; i++) {
            cout << setw(5) << i;
        }
        cout << endl;

        for (int i = 0; i < V; i++) {
            cout << setw(3) << i << ":";
            for (int j = 0; j < V; j++) {
                if (dist[i][j] == INF) {
                    cout << setw(5) << "INF";
                } else {
                    cout << setw(5) << dist[i][j];
                }
            }
            cout << endl;
        }
    }

    // 找图的中心（到其他所有节点距离之和最小的节点）
    int findCenter() {
        int center = 0;
        long long minSum = INF;

        for (int i = 0; i < V; i++) {
            long long sum = 0;
            for (int j = 0; j < V; j++) {
                if (dist[i][j] != INF) {
                    sum += dist[i][j];
                }
            }
            if (sum < minSum) {
                minSum = sum;
                center = i;
            }
        }

        return center;
    }

    // 找图的直径（最远的两个节点之间的距离）
    long long getDiameter() {
        long long diameter = 0;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] != INF) {
                    diameter = max(diameter, dist[i][j]);
                }
            }
        }
        return diameter;
    }
};

// 使用示例
int main() {
    Graph g(4);
    g.addEdge(0, 1, 3);
    g.addEdge(0, 3, 7);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 1);

    bool noNegativeCycle = g.floydWarshall();

    if (!noNegativeCycle) {
        cout << "Graph contains negative cycle!" << endl;
    } else {
        g.printDistances();

        cout << "\nShortest path from 0 to 3: ";
        vector<int> path = g.getPath(0, 3);
        for (int v : path) {
            cout << v << " ";
        }
        cout << "\nDistance: " << g.getDistance(0, 3) << endl;

        cout << "\nGraph center: " << g.findCenter() << endl;
        cout << "Graph diameter: " << g.getDiameter() << endl;
    }

    return 0;
}
