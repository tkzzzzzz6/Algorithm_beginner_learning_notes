/*
 * @Author: tkzzzzzz6
 * @Date: 2026-02-05 15:24:28
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-02-05 15:30:09
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
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    unordered_map<ll, int> last;
    last.reserve(n * 2);
    last.max_load_factor(0.5f);

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        int prev = 0;
        auto it = last.find(a[i]);
        if (it != last.end())
            prev = it->second;

        ll cntL = (ll)i - prev;
        ll len = (ll)n - i + 1;
        ll temp = len * (len + 1) / 2;

        ans += cntL * temp;

        last[a[i]] = i;
    }

    cout << ans << endl;
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
