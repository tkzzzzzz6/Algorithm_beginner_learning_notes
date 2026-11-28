/*
 * @Author: tkzzzzzz6
 * @Date: 2026-02-06 09:34:01
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-02-06 15:53:04
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

const ll N = 5e5 + 5, mod = 1e9 + 7, inf = 2e18;
const double eps = 1e-9;
const double PI = 3.1415926;

il void solve() {
    int n, m;
    cin >> n >> m;
    if (n % (m + 1) == 0)
        cout << "NO\n";
    else
        cout << "YES\n";
}

int main() {
    fastio;

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
