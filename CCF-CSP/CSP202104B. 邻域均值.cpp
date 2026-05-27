/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-27 08:59:09
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-27 10:04:32
 */
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, L, r, t;
    cin >> n >> L >> r >> t;

    vector<vector<int>> A(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];

    vector<vector<long long>> sum(n, vector<long long>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            sum[i][j] += A[i][j];
            if (i > 0) sum[i][j] += sum[i - 1][j];
            if (j > 0) sum[i][j] += sum[i][j - 1];
            if (i > 0 && j > 0) sum[i][j] -= sum[i - 1][j - 1];
        }

    auto query = [&](int x1, int y1, int x2, int y2) -> long long {
        long long res = sum[x2][y2];
        if (x1 > 0) res -= sum[x1 - 1][y2];
        if (y1 > 0) res -= sum[x2][y1 - 1];
        if (x1 > 0 && y1 > 0) res += sum[x1 - 1][y1 - 1];
        return res;
    };

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x1 = max(0, i - r), y1 = max(0, j - r);
            int x2 = min(n - 1, i + r), y2 = min(n - 1, j + r);
            long long s = query(x1, y1, x2, y2);
            int m = (x2 - x1 + 1) * (y2 - y1 + 1);
            if (s <= 1LL * t * m) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
