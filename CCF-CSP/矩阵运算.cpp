/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-27 21:26:47
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-27 21:59:17
 */
#include <iostream>

using namespace std;
const int N = 1e4 + 5;
int w[N], q[N][25], v[N][25], k[N][25];
long long back[25][25], t[N][25];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, d;
    cin >> n >> d;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < d; ++j)
            cin >> q[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < d; ++j)
            cin >> k[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < d; ++j)
            cin >> v[i][j];

    for (int i = 0; i < n; ++i) cin >> w[i];

    // 先计算k转置乘v
    for (int i = 0; i < d; ++i)
        for (int j = 0; j < d; ++j)
            for (int r = 0; r < n; ++r)
                back[i][j] += 1LL * k[r][i] * v[r][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < d; ++j)
            for (int r = 0; r < d; ++r)
                t[i][j] += 1LL * q[i][r] * back[r][j];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            if (j) cout << ' ';
            cout << w[i] * t[i][j];
        }
        cout << '\n';
    }

    return 0;
}
