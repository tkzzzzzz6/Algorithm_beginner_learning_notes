/*
 * @Author: tkzzzzzz6
 * @Date: 2026-11-21 23:30:34
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-11-22 00:44:08
 */
#include <iostream>

using namespace std;

void solve() {
    int x, ans = 0;
    cin >> x;
    for (int n = 1; n <= x; ++n) {
        for (int c = 0; c < n; ++c) {
            int a = n - c;
            if (a <= c + 1) {
                ans = a * (2 * c + 3 - a) / 2;
            } else {
                ans = (c + 1) * (c + 2) / 2 + (a - c - 1);
            }
            if (ans >= x) {
                cout << n << '\n';
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
