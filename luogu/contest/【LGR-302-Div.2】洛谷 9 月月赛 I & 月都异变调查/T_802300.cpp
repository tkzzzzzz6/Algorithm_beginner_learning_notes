#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define il inline
#define endl '\n'
using namespace std;

#define pb push_back
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);

typedef long long ll;
typedef unsigned long long ull;

il void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges(m);

    vector<int> deg(n + 1, 0);

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
        deg[u]++;
        deg[v]++;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    // 1. 计算完全图对应的边数
    ull total_edges = 1ULL * n * (n - 1) / 2;
    ull missing = total_edges - m;

    // 2. 缺失的边 <= n - 1
    if (missing <= n - 1) {
        cout << missing << '\n';
        vector<vector<bool>> has_edge(n + 1, vector<bool>(n + 1, false));

        for (const auto &edge : edges) {
            has_edge[edge.first][edge.second] = true;
            has_edge[edge.second][edge.first] = true;
        }

        for (int u = 1; u <= n; ++u) {
            for (int v = u + 1; v <= n; ++v) {
                if (has_edge[u][v] == false) cout << u << ' ' << v << '\n';
            }
        }
    }

    // 3. 缺失的边数 > n - 1,需要构成菊花图即中心节点的度数>=2
    else {
        int center = 1;
        for (int i = 2; i <= n; ++i) {
            if (deg[i] > deg[center]) {
                center = i;
            }
        }

        vector<bool> is_neighbor(n + 1, false);
        for (auto neighbor : adj[center]) {
            is_neighbor[neighbor] = true;
        }

        vector<int> need_connect;
        for (int i = 1; i <= n; ++i) {
            if (i != center && !is_neighbor[i]) {
                need_connect.pb(i);
            }
        }

        cout << need_connect.size() << '\n';

        for (auto v : need_connect) {
            cout << center << ' ' << v << '\n';
        }
    }
}

int main() {
    fastio;

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
