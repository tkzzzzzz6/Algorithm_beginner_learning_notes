/*
 * @Author: tkzzzzzz6
 * @Date: 2026-02-07 16:04:30
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-02-07 16:04:33
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
    vector<ll> a(n);
    ll sum_a = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum_a += a[i];
    }

    vector<ll> b(m);
    ll sum_b = 0;
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        sum_b += b[i];
    }

    if (sum_a == sum_b) {
        cout << 1 << endl;
        return;
    }

    int ans = 0;
    if (sum_a > sum_b) {
        sort(a.rbegin(), a.rend());
        for (auto val : a) {
            sum_a -= val;
            ++ans;
            if (sum_a <= sum_b)
                break;
        }
    } else {
        sort(b.rbegin(), b.rend());
        for (auto val : b) {
            sum_b -= val;
            ++ans;
            if (sum_a >= sum_b) {
                break;
            }
        }
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
