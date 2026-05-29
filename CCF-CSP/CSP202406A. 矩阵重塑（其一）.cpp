/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-28 22:37:33
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-28 22:41:25
 */
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, p, q;
    cin >> n >> m >> p >> q;

    int cnt = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int a;
            cin >> a;
            cout << a << ' ';
            if (cnt % q == 0) cout << '\n';
            cnt = (cnt + 1) % q;
        }
    }

    return 0;
}
