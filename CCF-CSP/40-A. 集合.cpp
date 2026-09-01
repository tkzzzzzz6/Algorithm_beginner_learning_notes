/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-25 15:10:48
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-26 09:54:57
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) { // 1-base
        cin >> a[i];
    }

    vector<vector<int>> s(m), t(m);
    vector<int> sxor(m), txor(m);

    for (int i = 0; i < m; ++i) {
        int size = 0;
        cin >> size;
        s[i].resize(size);
        int sumxor = 0;
        for (int j = 0; j < size; ++j) {
            cin >> s[i][j];
            sumxor ^= a[s[i][j]];
        }
        sxor[i] = sumxor;
    }

    for (int i = 0; i < m; ++i) {
        int size = 0;
        cin >> size;
        t[i].resize(size);
        int sumxor = 0;
        for (int j = 0; j < size; ++j) {
            cin >> t[i][j];
            sumxor ^= a[t[i][j]];
        }
        txor[i] = sumxor;
    }

    for (int i = 0; i < m; ++i) {
        bool realEqual = s[i] == t[i];
        bool xorEqual = sxor[i] == txor[i];

        if (realEqual) {
            cout << "correct\n";
        } else {
            cout << (xorEqual ? "wrong" : "correct") << '\n';
        }
    }

    return 0;
}
