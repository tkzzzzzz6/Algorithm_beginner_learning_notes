#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    int n;
    vector<int> fa, sz;
    vector<long long> dist; // a_x - a_fa[x]（find 后变成 a_x - a_root）

    DSU(int n = 0) { init(n); }

    void init(int n_)
    {
        n = n_;
        fa.resize(n + 1);
        sz.assign(n + 1, 1);
        dist.assign(n + 1, 0);
        for (int i = 0; i <= n; ++i)
        {
            fa[i] = i;
        }
    }

    int find(int x)
    {
        if (fa[x] == x)
            return x;
        int f = fa[x];
        fa[x] = find(f);
        dist[x] += dist[f];
        return fa[x];
    }

    // 加约束: a_u - a_v = k
    // 返回 true 表示不矛盾且已合并/确认; false 表示矛盾, 不修改并查集
    bool unite(int u, int v, long long k)
    {
        int ru = find(u);
        int rv = find(v);
        long long du = dist[u]; // a_u - a_ru
        long long dv = dist[v]; // a_v - a_rv

        if (ru == rv)
        {
            // 已在同一集合, 检查是否与现有约束矛盾
            // 当前已有: a_u - a_v = du - dv
            return (du - dv == k);
        }

        // 按大小合并
        if (sz[ru] < sz[rv])
        {
            // 把 ru 挂到 rv 上
            fa[ru] = rv;
            sz[rv] += sz[ru];
            // 需要满足: a_u - a_v = k
            // 推出: a_ru - a_rv = k - du + dv
            dist[ru] = k - du + dv; // a_ru - a_rv
        }
        else
        {
            // 把 rv 挂到 ru 上
            fa[rv] = ru;
            sz[ru] += sz[rv];
            // 需要满足: a_u - a_v = k
            // 推出: a_rv - a_ru = -k + du - dv
            dist[rv] = -k + du - dv; // a_rv - a_ru
        }
        return true;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T))
        return 0;
    while (T--)
    {
        int n, q;
        cin >> n >> q;

        // 点编号 0..n, 其中 0 为虚拟点, 表示值 0
        DSU dsu(n);

        while (q--)
        {
            int op;
            cin >> op;
            if (op == 1)
            {
                int u, v;
                long long k;
                cin >> u >> v >> k;
                bool ok = dsu.unite(u, v, k);
                if (ok)
                    cout << "OK\n";
                else
                    cout << "CONTRADICTION\n";
            }
            else if (op == 2)
            {
                int u;
                long long k;
                cin >> u >> k;
                // a_u = k 等价为 a_u - a_0 = k
                bool ok = dsu.unite(u, 0, k);
                if (ok)
                    cout << "OK\n";
                else
                    cout << "CONTRADICTION\n";
            }
            else
            { // op == 3
                int u, v;
                cin >> u >> v;
                int ru = dsu.find(u);
                int rv = dsu.find(v);
                if (ru != rv)
                {
                    cout << "UNKNOWN\n";
                }
                else
                {
                    long long ans = dsu.dist[u] - dsu.dist[v];
                    cout << ans << "\n";
                }
            }
        }
    }
    return 0;
}
