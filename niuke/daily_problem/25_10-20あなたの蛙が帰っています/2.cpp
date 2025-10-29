#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

// 快速幂
ll power(ll a, ll b, ll mod) {
    ll result = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) result = result * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return result;
}

// 逆元
ll inv(ll a, ll mod) {
    return power(a, mod - 2, mod);
}

// 计算 C(n) - C(n-1)
ll solve(int n) {
    if (n == 1) return 0;

    // 预计算阶乘
    vector<ll> fact(2 * n + 1);
    fact[0] = 1;
    for (int i = 1; i <= 2 * n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    // C(n) = (2n)! / ((n+1)! * n!)
    ll cn = fact[2 * n] * inv(fact[n + 1], MOD) % MOD * inv(fact[n], MOD) % MOD;

    // C(n-1) = (2n-2)! / (n! * (n-1)!)
    ll cn_1 = fact[2 * n - 2] * inv(fact[n], MOD) % MOD * inv(fact[n - 1], MOD) % MOD;

    return (cn - cn_1 + MOD) % MOD;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int T;
    cin >> T;

    for (int caseNum = 1; caseNum <= T; caseNum++) {
        int n;
        cin >> n;

        cout << "Case #" << caseNum << ": " << solve(n) << '\n';
    }

    return 0;
}