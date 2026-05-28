/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-26 18:59:16
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-26 19:08:36
 */
#include <iostream>
#include <vector>

using namespace std;

inline int f(int x, int k) {
    return ((x * x + k * k) % 8) ^ k;
}

inline int g(int x, int k) {
    int a = (x >> 6) & 7;
    int b = (x >> 3) & 7;
    int c = x & 7;

    int na = b;
    int nb = c ^ f(b, k);
    int nc = a ^ f(c, k);

    return na << 6 | nb << 3 | nc;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> k(m);
    for (int i = 0; i < m; ++i) cin >> k[i];

    vector<int> rev(512);
    for (int i = 0; i < 512; ++i) {
        int x = i;
        for (int j = 0; j < m; ++j) {
            x = g(x, k[j]);
        }
        rev[x] = i;
    }

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        cout << rev[a];
        if (i + 1 < n) cout << ' ';
    }

    cout << '\n';

    return 0;
}
