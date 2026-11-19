#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

using ll = long long;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
	return 0;
}

void solve() {
    ll n, x, m = INT_MAX;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        m = min(a[i], m);
    }
    ll L = 1, R = m + x;
    while (L < R) {
        ll mid = L + (R - L + 1) / 2;

        ll need = 0;
        for (int i = 0; i < n; ++i) {
            need += max(ll(0), mid - a[i]);
            if (need > x) break;
        }

        if (need <= x)
            L = mid;
        else
            R = mid - 1;
    }
    cout << L << '\n';
}
