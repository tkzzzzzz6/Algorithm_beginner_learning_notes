#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;  // 模数

// 快速幂算法 
// 功能：计算 a^b % mod
// 原理：利用二进制拆分，将指数b表示为二进制形式
// 例如：3^13 = 3^(1101?) = 3^8 × 3^4 × 3^1
ll power(ll a, ll b, ll mod) {
    ll result = 1;      // 初始结果为1
    a %= mod;           // 先对a取模，防止溢出

    while (b > 0) {     // 当指数大于0时继续
        // 检查b的最低位是否为1
        if (b & 1) {    // 相当于 if (b % 2 == 1)
            // 如果当前位是1，将对应的a^(2^i)乘入结果
            result = result * a % mod;
        }

        // a自乘，从a^1变成a^2, a^4, a^8, ...
        a = a * a % mod;

        // b右移一位，相当于b除以2
        b >>= 1;        // 相当于 b /= 2
    }

    return result;
}

// 模逆元 
// 功能：计算 a 在模 mod 下的乘法逆元
// 定义：若 a × x ≡ 1 (mod p)，则称x为a的逆元，记作a^(-1)
// 原理：根据费马小定理，当p为质数时，a^(p-1) ≡ 1 (mod p)
//      因此 a^(p-2) × a ≡ 1 (mod p)
//      所以 a^(-1) = a^(p-2) mod p
ll inv(ll a, ll mod) {
    // 利用费马小定理：a^(-1) = a^(mod-2) mod mod
    return power(a, mod - 2, mod);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int T;
    cin >> T; 

    // 卡特兰数C(n)表示:n个元素的合法出栈序列数
    // 卡特兰数：C(n) = (2n)! / ((n+1)! × n!)
    int maxN = 100005;  // 最大n值（根据题目数据范围1≤??≤10^5）
    vector<ll> catalan(maxN);

    // 初始条件
    catalan[0] = 1;  // C(0) = 1
    catalan[1] = 1;  // C(1) = 1

    // 递推计算卡特兰数 
    // 递推公式：C(n) = C(n-1) × 2(2n-1) / (n+1)
    // 推导过程：
    // C(n) = (2n)! / ((n+1)! × n!)
    // C(n-1) = (2n-2)! / (n! × (n-1)!)
    // C(n) / C(n-1) = [(2n)! / ((n+1)! × n!)] / [(2n-2)! / (n! × (n-1)!)]
    //                = (2n)! × n! × (n-1)! / ((n+1)! × n! × (2n-2)!)
    //                = (2n)(2n-1)(2n-2)! / ((n+1) × n × (n-1)! × n!)
    //                = (2n)(2n-1) / ((n+1) × n)
    //                = 2(2n-1) / (n+1)
    // 因此：C(n) = C(n-1) × 2(2n-1) / (n+1)

    for (int i = 2; i < maxN; i++) {
        // 计算 C(i) = C(i-1) × 2(2i-1) / (i+1)

        // 步骤1：C(i-1) × 2(2i-1)
        catalan[i] = catalan[i - 1] * (4 * i - 2) % MOD;

        // 步骤2：除以 (i+1)
        // 在模运算下，除法 = 乘以逆元
        // a / b ≡ a × b^(-1) (mod p)
        catalan[i] = catalan[i] * inv(i + 1, MOD) % MOD;
    }

    // 处理每个测试用例 
    for (int caseNum = 1; caseNum <= T; caseNum++) {
        int n;
        cin >> n;

        ll result;

        // 特判：n=1时，A1不能第一个出栈，无解
        if (n == 1) {
            result = 0;
        }
        else {
            // 答案 = C(n) - C(n-1)
            //  C(n)：所有合法的出栈序列数
            //  C(n-1)：A1第一个出栈的序列数（相当于剩余n-1个元素的标准问题）
            //  C(n) - C(n-1)：A1不第一个出栈的序列数

            result = (catalan[n] - catalan[n - 1] + MOD) % MOD;

            // 加MOD是为了防止结果为负数
            // 在模运算下，(a - b) % MOD 可能是负数
            // 正确做法：(a - b + MOD) % MOD
        }

        cout << "Case #" << caseNum << ": " << result << '\n';
    }

    return 0;
}