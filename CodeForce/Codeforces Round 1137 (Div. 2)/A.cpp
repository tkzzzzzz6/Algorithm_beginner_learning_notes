/*
 * @Author: tkzzzzzz6
 * @Date: 2026-11-22 17:19:40
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-11-22 17:26:20
 */
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long x;
        cin >> x;
        int ans = 0;
        while (x % 2 == 0) ++ans, x /= 2;
        cout << ((ans == 1) ? "No" : "Yes") << '\n';
    }
    return 0;
}
