/*
 * @Author: tkzzzzzz6
 * @Date: 2026-02-05 16:31:57
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-02-05 16:32:00
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
    ll n;
    cin >> n;
    int L = 0;
    while ((1LL << L) <= n)
        L++;

    ll x = n << L;
    ll y = x + n;

    cout << x << ' ' << y << endl;
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
