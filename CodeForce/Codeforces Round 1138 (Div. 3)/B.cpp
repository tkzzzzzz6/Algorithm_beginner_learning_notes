#include <cstddef>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, k, p;
        cin >> n >> k >> p;
        vector<ll> a(n);
        for (ll &x : a) cin >> x;
        sort(a.begin(), a.end());

        ll res = 0;
        int i = 0;
        while (i + k <= n) {
            ll sum = 0;
            for (int j = 0; j < k; ++j) sum += a[i + j];
            if (sum >= p)
                res += sum;
            else
                res += p;
            i += k;
        }
        while (i < n) res += a[i++];
        cout << res << '\n';
    }
    return 0;
}
