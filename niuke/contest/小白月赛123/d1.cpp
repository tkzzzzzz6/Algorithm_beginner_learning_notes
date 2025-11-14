#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (ll)4e18;

struct Edge
{
    int to;
    ll w;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m))
    {
        return 0;
    }

    int N = 2 * n; // 1..n: 无券  , n+1..2n: 有券
    vector<vector<Edge>> g(N + 1);
    g.reserve(N + 1);

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;

        int u0 = u; // 无券
        int v0 = v;
        int u1 = u + n; // 有券
        int v1 = v + n;

        // 1. 正常走（无券 -> 无券）
        g[u0].push_back({v0, w});
        g[v0].push_back({u0, w});

        // 2. 回头一次获得券（无券 -> 有券）
        ll two_w = w * 2;
        g[u0].push_back({u1, two_w});
        g[v0].push_back({v1, two_w});

        // 3. 使用券免费走（有券 -> 无券）
        g[u1].push_back({v0, 0});
        g[v1].push_back({u0, 0});
    }

    // Dijkstra
    vector<ll> dist(N + 1, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    int start = 1; // 1号点，无券状态
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u])
            continue;

        for (auto &e : g[u])
        {
            int v = e.to;
            ll nd = d + e.w;
            if (nd < dist[v])
            {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }

    ll ans = min(dist[n], dist[n + n]);
    if (ans >= INF / 2)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << ans << '\n';
    }

    return 0;
}
