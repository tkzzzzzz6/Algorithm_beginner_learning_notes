/*
 * @Author: tkzzzzzz6
 * @Date: 2026-10-21 21:26:41
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-10-21 21:49:51
 */
#include <iostream>

using namespace std;

using ll = long long;

const ll MOD = 99824353;

ll qpow(ll b, ll e) {
    ll r = 1;
    b %= MOD;
    while (e) {
        if (e & 1) {
            r = r * b % MOD;
        }
        b = b * b % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    ll n;
    cin >> n;

    if (n == 1) {
        cout << "0\n";
        return 0;
    }

    ll a = n, b = n - 1;
    if (a & 1)
        b >>= 1;
    else {
        a >>= 1;
    }

    ll c = (a % MOD) * (b % MOD) % MOD;

    cout << c * qpow(2, n - 2) % MOD << '\n';

    return 0;
}
