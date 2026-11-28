/*
 * @Author: tkzzzzzz6
 * @Date: 2026-01-22 22:21:35
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-01-22 22:21:39
 */

#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int x = m ^ n;
    int ans = 0;
    while (x != 0) {
        x &= x - 1;
        ++ans;
    }
    cout << ans;
    return 0;
}
// 64 位输出请用 printf("%lld")
