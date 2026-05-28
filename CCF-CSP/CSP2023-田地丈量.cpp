/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-28 08:06:15
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-28 13:10:13
 */
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n, a, b;
    long long ans = 0;
    cin >> n >> a >> b;

    for (int i = 0; i < n; ++i) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        long long xl = max(0LL, x1), yl = max(0LL, y1);
        long long xr = min(a, x2), yr = min(b, y2);

        if (xl < xr && yl < yr)
            ans += (xr - xl) * (yr - yl);
    }

    cout << ans << '\n';
    return 0;
}
