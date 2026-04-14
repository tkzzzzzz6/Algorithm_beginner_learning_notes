#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;  // ģ

// 㷨
// ܣ a^b % mod
// ԭöƲָ֣bʾΪʽ
// 磺3^13 = 3^(1101?) = 3^8  3^4  3^1
ll power(ll a, ll b, ll mod) {
    ll result = 1;      // ʼΪ1
    a %= mod;           // ȶaȡģֹ

    while (b > 0) {     // ָ0ʱ
        // bλǷΪ1
        if (b & 1) {    // ൱ if (b % 2 == 1)
            // ǰλ1Ӧa^(2^i)
            result = result * a % mod;
        }

        // aԳˣa^1a^2, a^4, a^8, ...
        a = a * a % mod;

        // bһλ൱b2
        b >>= 1;        // ൱ b /= 2
    }

    return result;
}

// ģԪ
// ܣ a ģ mod µĳ˷Ԫ
// 壺 a  x  1 (mod p)xΪaԪa^(-1)
// ԭݷСpΪʱa^(p-1)  1 (mod p)
//       a^(p-2)  a  1 (mod p)
//       a^(-1) = a^(p-2) mod p
ll inv(ll a, ll mod) {
    // ÷Сa^(-1) = a^(mod-2) mod mod
    return power(a, mod - 2, mod);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int T;
    cin >> T;

    // C(n)ʾ:nԪصĺϷջ
    // C(n) = (2n)! / ((n+1)!  n!)
    int maxN = 100005;  // nֵĿݷΧ1??10^5
    vector<ll> catalan(maxN);

    // ʼ
    catalan[0] = 1;  // C(0) = 1
    catalan[1] = 1;  // C(1) = 1

    // Ƽ㿨
    // ƹʽC(n) = C(n-1)  2(2n-1) / (n+1)
    // Ƶ̣
    // C(n) = (2n)! / ((n+1)!  n!)
    // C(n-1) = (2n-2)! / (n!  (n-1)!)
    // C(n) / C(n-1) = [(2n)! / ((n+1)!  n!)] / [(2n-2)! / (n!  (n-1)!)]
    //                = (2n)!  n!  (n-1)! / ((n+1)!  n!  (2n-2)!)
    //                = (2n)(2n-1)(2n-2)! / ((n+1)  n  (n-1)!  n!)
    //                = (2n)(2n-1) / ((n+1)  n)
    //                = 2(2n-1) / (n+1)
    // ˣC(n) = C(n-1)  2(2n-1) / (n+1)

    for (int i = 2; i < maxN; i++) {
        //  C(i) = C(i-1)  2(2i-1) / (i+1)

        // 1C(i-1)  2(2i-1)
        catalan[i] = catalan[i - 1] * (4 * i - 2) % MOD;

        // 2 (i+1)
        // ģ£ = Ԫ
        // a / b  a  b^(-1) (mod p)
        catalan[i] = catalan[i] * inv(i + 1, MOD) % MOD;
    }

    // ÿ
    for (int caseNum = 1; caseNum <= T; caseNum++) {
        int n;
        cin >> n;

        ll result;

        // Уn=1ʱA1ܵһջ޽
        if (n == 1) {
            result = 0;
        }
        else {
            //  = C(n) - C(n-1)
            //  C(n)кϷĳջ
            //  C(n-1)A1һջ൱ʣn-1Ԫصı׼⣩
            //  C(n) - C(n-1)A1һջ

            result = (catalan[n] - catalan[n - 1] + MOD) % MOD;

            // MODΪ˷ֹΪ
            // ģ£(a - b) % MOD Ǹ
            // ȷ(a - b + MOD) % MOD
        }

        cout << "Case #" << caseNum << ": " << result << '\n';
    }

    return 0;
}
