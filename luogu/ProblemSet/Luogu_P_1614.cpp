/*
 * @Author: tkzzzzzz6
 * @Date: 2026-06-03 14:22:55
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-06-03 14:36:13
 */
#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 3e3 + 5;
int a[maxN] = {0};

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int i = 0, windows = 0;
    for (int i = 0; i < m; ++i) {
        windows += a[i];
    }

    int res = windows;

    ++i;
    while (i < n) {
        windows = windows - a[i - m] + a[i];
        res = min(res, windows);
        ++i;
    }

    cout << res;

    return 0;
}
