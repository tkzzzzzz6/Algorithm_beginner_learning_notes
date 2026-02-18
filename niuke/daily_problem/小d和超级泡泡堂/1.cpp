#include <bits/stdc++.h>
#define il inline
#define endl '\n'
using namespace std;

#define pb push_back
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);

using ll = long long;

struct Point {
    int x;
    int y;
};

il void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> map(n + 1);
    int startX = 0, startY = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> map[i];
        for (int j = 0; j < m; ++j) {
            if (map[i][j] == '@') {
                startX = i;
                startY = j;
            }
        }
    }

    vector<vector<bool>> vis(n + 1, vector<bool>(m, false));
    array<int, 4> dx{-1, 1, 0, 0};
    array<int, 4> dy{0, 0, 1, -1};

    queue<Point> Q;
    Q.push({startX, startY});
    vis[startX][startY] = true;

    int ans = 0;
    while (!Q.empty()) {
        auto [cx, cy] = Q.front();
        Q.pop();

        for (int k = 0; k < 4; ++k) {
            int nx = cx + dx[k];
            int ny = cy + dy[k];
            if (nx < 1 || nx > n || ny < 0 || ny >= m)
                continue;
            if (vis[nx][ny] || map[nx][ny] == '#')
                continue;
            vis[nx][ny] = true;
            if (map[nx][ny] == '!') {
                map[nx][ny] = '.';
                ++ans;
            }
            Q.push({nx, ny});
        }
    }
    cout << ans << endl;
}

int main() {
    fastio;

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
