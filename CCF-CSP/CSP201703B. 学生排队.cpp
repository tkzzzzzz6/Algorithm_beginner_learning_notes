/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-27 15:26:57
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-27 15:42:17
 */
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = i + 1;

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int p, q;
        cin >> p >> q;
        int idx = 0;
        while (a[idx] != p) ++idx;

        a.erase(a.begin() + idx);
        a.insert(a.begin() + idx + q, p);
    }

    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << a[i];
    }

    cout << '\n';
}
