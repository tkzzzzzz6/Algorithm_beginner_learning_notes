/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-27 10:05:41
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-27 11:02:57
 */
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long b, c, l, r;
    cin >> b >> c >> l >> r;

    auto f = [=](long long b, long long c, long long x) -> long long {
        return x * x + b * x + c;
    };

    (l % 2 == 0) ? l = l : l += 1;

    long long res = 0;
    for (long long i = l; i <= r; i += 2) {
        res += f(b, c, i);
    }

    cout << 2 * res << endl;

    return 0;
}
