/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-26 21:45:57
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-26 21:53:28
 */
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, l;
    cin >> n >> m >> l;
    vector<int> h(l, 0);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            h[x]++;
        }

    for (int i = 0; i < l; ++i) {
        if (i) cout << ' ';
        cout << h[i];
    }

    cout << '\n';

    return 0;
}
