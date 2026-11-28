#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    ll sum = 0;
    vector<ll> nums(n); 
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        sum += nums[i];
    }

    auto calc = [&](ll x) -> ll {
        ll y = sum - (ll)(n - 1) * x;
        long long base = 0;
        long long best_delta = (1LL << 62);
        for (int i = 0; i < n; ++i) {
            ll dx = llabs(nums[i] - x);
            ll dy = llabs(nums[i] - y);
            base += dx;
            best_delta = min(best_delta, dy - dx);
        }
        ll totalL1 = base + best_delta;
        return totalL1 / 2;
    };

    ll avg = sum / n;

    if (sum % n == 0) {
        ll L1 = 0;
        for (ll v : nums)
            L1 += llabs(v - avg);
        cout << (L1 / 2) << endl; 
    } else {
        ll q = avg; // floor(sum/n)
        ll res = min(calc(q), calc(q + 1));
        cout << res << endl;
    }

    return 0;
}
