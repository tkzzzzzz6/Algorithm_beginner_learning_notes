#include <iostream>
using namespace std;
typedef long long ll;

const int N = 1e7 + 10;

const ll mod = 1e9 + 7;
int a[10];
ll f[N];

// 快速幂
ll qmi(ll a,ll b,ll mod){
    ll res = 1;
    while(b){
        if(b & 1)
            res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}

int n;

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    for (int i = 0; i < 10; ++i) {
        cin >> a[i];
    }

    ll ans = 0;
    f[0] = 1;
    f[1] = 1;
    // 采用递推的方式计算阶乘
    for (int i = 2; i <= N;++i){
        f[i] = f[i - 1] * i % mod;
    }


    ll num1 = 0;
    for (int i = 0; i < 10;++i){
        num1 += a[i];
    }

    ll num2 = 1;
    for (int i = 0; i < 10;++i){
        if(a[i] != 0)
            num2 = (num2 * f[a[i]]) % mod;
    }
    // 采用快速幂计算逆元
    cout << f[num1] * qmi(num2, mod - 2, mod) % mod;
    return 0;
}

