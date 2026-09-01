/*
 * @Author: tkzzzzzz6
 * @Date: 2026-06-01 15:43:06
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-06-02 14:41:01
 */
#include <iostream>
// 52*7*x + 52*21*k = N
// x + 3k = N/364
// M - x = 3*k
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int m = n / 364;
    int x = 100;
    for (; x >= 0; --x) {
        int k = (m - x) / 3;
        if (((m - x) % 3 == 0) && k > 0) {
            cout << x << '\n'
                 << k;
            break;
        }
    }
    return 0;
}
