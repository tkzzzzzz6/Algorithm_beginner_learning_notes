/*
 * @Author: tkzzzzzz6
 * @Date: 2026-09-25 14:10:56
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-09-25 14:24:07
 */
#include <iostream>
#include <algorithm>
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
    int n;
    cin >> n;
    int ans = 100;
    int nmin = 100, nmax = 400;
    while (n--) {
        int x, y;
        cin >> x >> y;
        x = min(50, x);
        ans -= x;
        ans = max(ans, nmin);
        ans += y;
        ans = min(nmax, ans);
    }
    cout << ans << '\n';
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
