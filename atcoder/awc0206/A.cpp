/*
 * @Author: tkzzzzzz6
 * @Date: 2026-11-23 19:08:14
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-11-23 19:22:52
 */
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    string ans;
    int n;
    cin >> n;
    ans.reserve(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == 0)
            ans += '-';
        else if (x == 10)
            ans += 'X';
        else
            ans += char('0' + x);
    }
    cout << ans << '\n';
    return 0;
}
