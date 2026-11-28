#include <iostream>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

ll Pow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll Inv(ll a) {
    return Pow(a, MOD - 2);
}

int n;
int q;
int a[100010];
int pre[100010] = {1};
int invPre[100010];

void Solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = (ll)pre[i - 1] * a[i] % MOD;
    }
    invPre[n] = Inv(pre[n]);
    for (int i = n; i > 0; --i) {
        invPre[i - 1] = (ll)invPre[i] * a[i] % MOD;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << (ll)pre[r] * invPre[l - 1] % MOD << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solve();
    return 0;
}
// 64 位输出请用 printf("%lld")

