/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-28 08:06:15
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-28 17:53:50
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int a, b;
    scanf("%d%d%d", &n, &a, &b);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

        int xl = max(0, x1), yl = max(0, y1);
        int xr = min(a, x2), yr = min(b, y2);

        if (xl < xr && yl < yr)
            ans += (xr - xl) * (yr - yl);
    }

    printf("%d\n", ans);
    return 0;
}
