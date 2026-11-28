#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 6;
const ll INF = 1e18;

int n, c[N];
ll w[N], mx1[N], mx2[N], ans[N];
vector<int> e[N];

void dfs1(int u, int f) {
    mx1[u] = mx2[u] = 0;
    for (int v : e[u]) if (v != f) {
        dfs1(v, u);
        mx2[u] = max(mx2[u], w[v] + mx1[v]); 
        if (mx2[u] > mx1[u]) swap(mx1[u], mx2[u]);
    }
}

void dfs2(int u, int f, ll fw) {
    mx2[u] = max(mx2[u], fw);
    if (mx2[u] > mx1[u]) swap(mx1[u], mx2[u]);
    ans[c[u]] = max(ans[c[u]], w[u] + mx1[u] + mx2[u]);
    
    for (int v : e[u]) if (v != f) {
        dfs2(v, u, w[u] + (w[v] + mx1[v] == mx1[u] ? mx2[u] : mx1[u]));
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v); e[v].push_back(u);
    }
    fill_n(ans + 1, n, -INF);
    dfs1(1, 0);
    dfs2(1, 0, 0);
    for (int i = 1; i <= n; i++) {
        cout << (ans[i] == -INF ? -1 : ans[i]) << " \n"[i == n];
    }
    for (int i = 1; i <= n; i++) e[i].clear();
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    if (cin >> T) while (T--) solve();
}
