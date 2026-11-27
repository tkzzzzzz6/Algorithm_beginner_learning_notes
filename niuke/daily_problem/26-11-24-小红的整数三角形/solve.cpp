/*
 * @Author: tkzzzzzz6
 * @Date: 2026-11-24 12:11:59
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-11-24 12:15:45
 */
#include <iostream>
using namespace std;

using ll = long long;

int main() {
    ll x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll dx = x2 - x1;
    // x1 - u,y1 - v
    if (dx != 0)
        cout << x1 << ' ' << y1 + 2;
    else
        cout << x1 + 2 << ' ' << y1;

    return 0;
}
// 64 位输出请用 printf("%lld")
