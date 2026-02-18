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
    int n, q;
    ll s;
    cin >> n >> q >> s;
    vector<ll> pre(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        pre[i] = pre[i - 1] + t;
    }

    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        ll y;
        cin >> y;
        ll ans = s + pre[x - 1] + (y - 1);

        cout << ans << endl;
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
