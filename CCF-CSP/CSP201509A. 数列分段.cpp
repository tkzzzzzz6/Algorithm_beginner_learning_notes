/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-28 18:07:24
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-28 18:12:42
 */
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int a = -1, b = -1;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> b;
        if (b != a) ++res;
        a = b;
    }

    cout << res << '\n';

    return 0;
}
