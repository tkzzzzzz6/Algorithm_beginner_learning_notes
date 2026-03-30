#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  // n = read(),m = read();
  int ans = 0;
  vector<vector<int>> a(n + 1), b(n + 1);
  vector<int> s, t, w(n + 1, 0), vis(n + 1, 0);

  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    // u = read(),v = read();
    a[u].push_back(v);
    b[v].push_back(u);
  }

  for (int i = 1; i <= n; ++i) {
    if (b[i].size() == 0 && a[i].size() != 0) {
      s.push_back(i);
    }
    if (a[i].size() == 0 && b[i].size() != 0) {
      t.push_back(i);
      w[i] = 1;
    }
  }

  auto dfs = [&](int fa, int u, auto dfs) -> void {
    vis[u] = 1;
    for (auto v : a[u]) {
      if (v == fa)
        continue;
      if (!vis[v])
        dfs(u, v, dfs);
      w[u] += w[v];
    }
  };

  for (auto u : s) {
    vis[u] = 1;
    dfs(0, u, dfs);
  }

  for (auto x : s) {
    ans += w[x];
  }

  cout << ans << '\n';

  return 0;
}
