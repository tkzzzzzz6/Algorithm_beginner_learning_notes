/*
 * @Author: tkzzzzzz6
 * @Date: 2026-01-31 19:46:23
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-01-31 20:03:21
 */
#include <bits/stdc++.h>
#define il inline
#define endl '\n'
using namespace std;

#define pb push_back
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);

typedef long long ll;
typedef unsigned long long ull;

il void solve() {
    string n;
    cin >> n;

    int len = n.size();
    int exp = len - 1; // 指数始终是长度减1

    if (len == 1) {
        cout << n[0] << ".0*10^0\n";
        return;
    }

    char a = n[0];
    char b = n[1];

    // 判断是否需要四舍五入
    if (len >= 3 && n[2] >= '5') {
        if (b == '9') {
            if (a == '9') {
                // 99x -> 1.0*10^(exp+1)
                cout << "1.0*10^" << exp + 1 << "\n";
            } else {
                // 19x -> 2.0*10^exp
                cout << char(a + 1) << ".0*10^" << exp << "\n";
            }
        } else {
            // 12x -> 1.3*10^exp
            cout << a << '.' << char(b + 1) << "*10^" << exp << "\n";
        }
    } else {
        // 不需要进位或只有两位数
        cout << a << '.' << b << "*10^" << exp << "\n";
    }
}

int main() {
    fastio;

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
