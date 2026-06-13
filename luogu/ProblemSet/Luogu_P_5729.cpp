/*
 * @Author: tkzzzzzz6
 * @Date: 2026-06-02 21:20:09
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-06-02 21:28:11
 */
#include <iostream>

using namespace std;
const int MaxN = 30;
int a[MaxN][MaxN][MaxN] = {0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int w, x, h;
    cin >> w >> x >> h;
    int q;
    cin >> q;
    while (q--) {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        for (int i = x1; i <= x2; ++i)
            for (int j = y1; j <= y2; ++j)
                for (int k = z1; k <= z2; ++k)
                    a[i][j][k] = 1;
    }

    int res = 0;
    for (int i = 1; i <= w; ++i)
        for (int j = 1; j <= x; ++j)
            for (int k = 1; k <= h; ++k)
                if (a[i][j][k] == 0) ++res;

    cout << res << '\n';

    return 0;
}
