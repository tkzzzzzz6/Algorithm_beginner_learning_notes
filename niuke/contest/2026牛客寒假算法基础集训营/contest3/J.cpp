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
    ll n, q;
    cin >> n >> q;
    while (q--) {
        ll x;
        cin >> x;

        // ll s = 1;
        // while(s <= x)s <<= 1;
        // s >>= 1;
        ll s = 1ULL << (63 - __builtin_clzll(x));

        ll end = (s << 1) - 1;
        ll real_end = min(end, n);

        cout << (real_end - s + 1) << endl;
    }
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
