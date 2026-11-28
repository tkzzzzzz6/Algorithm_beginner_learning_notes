#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, a1, m;
    cin >> n >> a1 >> m;

    vector<ll> A(n + 1);
    A[1] = a1;

    for (ll i = 2; i <= n; i++) {
        A[i] = (A[i - 1] + 7LL * i) % m; // A的递推公式
    }

    vector<ll> B(n + 1, 0);

    for (ll i = 1; i <= n; i++) {
        for (ll j = i; j <= n; j += i) {
            B[j] += A[i]; // 筛法
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
        ans ^= B[i];
    cout << ans;
}
