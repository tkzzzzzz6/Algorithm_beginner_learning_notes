/*
 * @Author: tkzzzzzz6
 * @Date: 2026-02-05 16:06:12
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-02-05 16:06:15
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    vector<int> deg(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++; deg[v]++;
    }

    // 1) 收集不同度数并排序
    vector<int> uniq;
    uniq.reserve(n);
    for (int i = 1; i <= n; i++) uniq.push_back(deg[i]);
    sort(uniq.begin(), uniq.end());
    uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());
    int k = (int)uniq.size();

    // 2) 把每个点按度数分桶：bucket[idx] 存度数 = uniq[idx] 的点
    // idx 是 0..k-1
    vector<vector<int>> bucket(k);
    bucket.reserve(k);
    for (int i = 1; i <= n; i++) {
        int idx = (int)(lower_bound(uniq.begin(), uniq.end(), deg[i]) - uniq.begin());
        bucket[idx].push_back(i);
    }

    vector<int> ans(n + 1, -1);
    if (k == 1) {
        // 全部同度数，没有更高级
        for (int i = 1; i <= n; i++) cout << -1 << (i == n ? '\n' : ' ');
        return 0;
    }

    // sources：当前阈值以上（>= uniq[t]）的所有点
    vector<int> sources;
    sources.reserve(n);

    // 3) 从最高度数层往下处理：
    // 对于 t = k-1..1:
    //   sources 加入 bucket[t]（度数=uniq[t]）
    //   BFS 求到 sources 的最短路 dist
    //   把 bucket[t-1] 这一层的答案赋值为 dist[点]
    for (int t = k - 1; t >= 1; t--) {
        // 把这一层加入 sources（阈值 >= uniq[t] 的源点集合）
        for (int v : bucket[t]) sources.push_back(v);

        // 多源 BFS
        vector<int> dist(n + 1, -1);
        queue<int> q;
        for (int s : sources) {
            dist[s] = 0;
            q.push(s);
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        // 这一轮 BFS 得到的是：到“度数 >= uniq[t]”的最短距离
        // 所以可以填：度数 = uniq[t-1] 的点（因为它们要找更高级，即 >= uniq[t]）
        for (int x : bucket[t - 1]) {
            ans[x] = dist[x];
        }
    }

    // 最高层 bucket[k-1] 没有更高级，保持 -1
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? '\n' : ' ');
    }
    return 0;
}
