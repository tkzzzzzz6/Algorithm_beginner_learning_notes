/*
 * @Author: tkzzzzzz6
 * @Date: 2026-02-03 17:39:22
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-02-05 12:52:26
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

static const int MOD = 998244353;

il void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    vector<int> dp(n + 1, 0), pre(n + 1, 0);
    dp[0] = 1;
    pre[0] = 1;

    int L = 1;
    int mask = 0;

    for (int i = 1; i <= n; ++i) {
        while ((mask & a[i]) != 0) {
            mask ^= a[L];
            ++L;
        }
        mask |= a[i];

        int left = L - 2;
        int val = pre[i - 1] - (left >= 0 ? pre[left] : 0);
        if (val < 0)
            val += MOD;
        dp[i] = val;

        pre[i] = pre[i - 1] + dp[i];
        if (pre[i] >= MOD)
            pre[i] -= MOD;
    }
    cout << dp[n] << endl;
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
