/*
 * @Author: tkzzzzzz6
 * @Date: 2026-02-09 14:49:17
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-02-09 15:02:11
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

const int DX[13] = {0, 1, -1, 0, 0, 2, -2, 0, 0, 1, 1, -1, -1};
const int DY[13] = {0, 0, 0, 1, -1, 0, 0, 2, -2, 1, -1, 1, -1};

// 要选中的区域是菱形,一共13个点
il void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> a(n, vector<ll>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    }
    vector<vector<ll>> S(n, vector<ll>(m, 0));
    priority_queue<tuple<ll, int, int>> pq;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ll sum = 0;
            for (int t = 0; t < 13; ++t) {
                int x = i + DX[t];
                int y = j + DY[t];
                if (0 <= x && x < n && 0 <= y && y < m) {
                    sum += a[x][y];
                }
            }
            S[i][j] = sum;
            pq.emplace(sum, i, j);
        }
    }

    while (q--) {
        int x, y;
        ll z;
        cin >> x >> y >> z;
        --x;
        --y;
        for (int t = 0; t < 13; ++t) {
            int cx = x + DX[t];
            int cy = y + DY[t];
            if (0 <= cx && cx < n && 0 <= cy && cy < m) {
                S[cx][cy] += z;
                pq.emplace(S[cx][cy], cx, cy);
            }
        }

        while (1) {
            auto [val, i, j] = pq.top();
            if (val == S[i][j]) {
                cout << i + 1 << ' ' << j + 1 << endl;
                break;
            }
            pq.pop();
        }
    }
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
