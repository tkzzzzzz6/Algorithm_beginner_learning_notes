/*
 * @Author: tkzzzzzz6
 * @Date: 2026-06-02 15:21:33
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-06-02 15:41:29
 */
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int l, m;
    cin >> l >> m;
    vector<int> a(l + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        for (int i = u; i <= v; ++i) {
            if (a[i] != 1) a[i] = 1;
        }
    }

    int res = 0;
    for (int i = 0; i <= l; ++i) {
        if (a[i] == 0) res++;
    }

    cout << res << '\n';
}
