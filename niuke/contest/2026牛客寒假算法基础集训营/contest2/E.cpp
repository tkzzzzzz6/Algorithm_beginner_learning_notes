/*
 * @Author: tkzzzzzz6
 * @Date: 2026-02-05 16:40:33
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-02-05 16:48:25
 */
#include <bits/stdc++.h>
#define il inline
#define endl '\n'
using namespace std;

#define pb push_back
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);

typedef long long ll;
typedef unsigned long long ull;

const ll N = 5e5 + 5, mod = 1e9 + 7, inf = 2e18;
const double eps = 1e-9;
const double PI = 3.1415926;

static const int dx[4] = {-1, 1, 0, 0};
static const int dy[4] = {0, 0, -1, 1};

il void solve() {
    int m, n;
    cin >> n >> m;
    vector<string> a(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<string> out(n, string(m, 'N'));

    auto inside = [&](int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char v = a[i][j];
            bool ok = false;

            for (int dir = 0; dir < 4 && !ok; ++dir) {
                int ni = i + dx[dir], nj = j + dy[dir];
                if (inside(ni, nj) && a[ni][nj] == v)
                    ok = true;
            }

            if (!ok) {
                for (int dir1 = 0; dir1 < 4 && !ok; ++dir1) {
                    int ni = i + dx[dir1], nj = j + dy[dir1];
                    if (!inside(ni, nj))
                        continue;

                    for (int dir2 = 0; dir2 < 4 && !ok; ++dir2) {
                        int xi = ni + dx[dir2], yj = nj + dy[dir2];
                        if (!inside(xi, yj))
                            continue;
                        if (xi == i && yj == j)
                            continue;
                        if (a[xi][yj] == v)
                            ok = true;
                    }
                }
            }

            out[i][j] = ok ? 'Y' : 'N';
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << out[i] << endl;
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
