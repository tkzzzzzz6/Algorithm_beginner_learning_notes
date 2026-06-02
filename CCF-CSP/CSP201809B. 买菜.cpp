/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-28 21:31:46
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-28 21:36:22
 */
#include <iostream>

using namespace std;

const int N = 1e6;

int d[N] = {0};

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < 2 * n; ++i) {
        int a, b;
        cin >> a >> b;
        for (int i = a; i < b; ++i) {
            d[i]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (d[i] == 2) ++ans;
    }

    cout << ans << '\n';

    return 0;
}
