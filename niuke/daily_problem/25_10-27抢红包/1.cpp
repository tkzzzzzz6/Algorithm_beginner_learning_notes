#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

// 我们每次到下一个人的时候,对应的期望都会变成原来的一半,所以对应的结果是w/2^k mod 1e9+7
// 快速幂
// 计算 base^exp % mod
ll power(ll base, ll exp)
{
    ll res = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)
            res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll w, n, k;
    cin >> w >> n >> k;

    // 计算 2 在模 mod 意义下的乘法逆元,逆元可以类比线性代数中求逆矩阵
    ll inv2 = power(2, mod - 2);

    // 计算 (2^k) 在模 mod 意义下的乘法逆元，即 (2 的模逆元)^k
    ll inv2_k = power(inv2, k);

    // 期望 = (W * (2^k 的模逆元)) % mod
    ll ans = (w * inv2_k) % mod;

    cout << ans << endl;

    return 0;
}
