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

static const long long MOD = 998244353LL;
const int MAXN = 200000;

vector<ll> fac(MAXN + 1, 1);

il void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int m = INT_MAX;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        m = min(m, b[i]);
    }
    int k = 0;
    for (int x : a) {
        if (x > m)
            ++k;
    }
    ll ans = fac[k] * fac[n - k] % MOD;
    cout << ans << endl;
}

int main() {
    fastio;
    for (int i = 1; i <= MAXN; ++i)
        fac[i] = fac[i - 1] * i % MOD;

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
