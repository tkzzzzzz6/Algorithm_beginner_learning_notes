/*
 * 组合数取模 (Binomial Coefficient Modulo)
 * 用途：计算 C(n, r) mod p
 * 时间复杂度：取决于方法，从 O(1) 到 O(n)
 */

#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

// 方法1：预处理阶乘和逆元（适用于多次查询）
class CombinationMod {
private:
    vector<long long> fact, invFact;
    int maxN;

    long long power(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) result = result * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return result;
    }

    long long modInverse(long long a, long long mod) {
        return power(a, mod - 2, mod);  // 费马小定理
    }

public:
    CombinationMod(int n) : maxN(n) {
        fact.resize(maxN + 1);
        invFact.resize(maxN + 1);

        // 预处理阶乘
        fact[0] = 1;
        for (int i = 1; i <= maxN; i++) {
            fact[i] = fact[i-1] * i % MOD;
        }

        // 预处理逆元
        invFact[maxN] = modInverse(fact[maxN], MOD);
        for (int i = maxN - 1; i >= 0; i--) {
            invFact[i] = invFact[i+1] * (i+1) % MOD;
        }
    }

    long long C(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n-r] % MOD;
    }

    long long P(int n, int r) {  // 排列数 P(n, r) = n! / (n-r)!
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[n-r] % MOD;
    }

    // 多重集合的组合数：从n个元素中选r个，可重复
    // H(n, r) = C(n+r-1, r)
    long long H(int n, int r) {
        return C(n + r - 1, r);
    }
};

// 方法2：Lucas定理（适用于p为素数且较小的情况）
// C(n, r) mod p = C(n/p, r/p) * C(n%p, r%p) mod p
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

long long modInverse(long long a, long long mod) {
    return power(a, mod - 2, mod);
}

long long smallC(long long n, long long r, long long p) {
    if (r > n) return 0;
    long long numerator = 1, denominator = 1;
    for (long long i = 0; i < r; i++) {
        numerator = numerator * ((n - i) % p) % p;
        denominator = denominator * ((i + 1) % p) % p;
    }
    return numerator * modInverse(denominator, p) % p;
}

long long lucas(long long n, long long r, long long p) {
    if (r == 0) return 1;
    return lucas(n / p, r / p, p) * smallC(n % p, r % p, p) % p;
}

// 方法3：递推计算Pascal三角（适用于n和r都较小的情况）
vector<vector<long long>> pascalTriangle(int n) {
    vector<vector<long long>> C(n + 1, vector<long long>(n + 1, 0));

    for (int i = 0; i <= n; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
        }
    }

    return C;
}

// 方法4：在线计算（不预处理）
long long combinationOnline(long long n, long long r, long long mod) {
    if (r > n || r < 0) return 0;
    if (r == 0 || r == n) return 1;

    // 优化：C(n, r) = C(n, n-r)
    r = min(r, n - r);

    long long numerator = 1, denominator = 1;

    for (long long i = 0; i < r; i++) {
        numerator = numerator * ((n - i) % mod) % mod;
        denominator = denominator * ((i + 1) % mod) % mod;
    }

    return numerator * modInverse(denominator, mod) % mod;
}

// 方法5：扩展Lucas定理（适用于p不是素数的情况）
// 使用中国剩余定理CRT

// Catalan数：C_n = C(2n, n) / (n+1)
long long catalan(int n, CombinationMod& comb) {
    return comb.C(2 * n, n) * modInverse(n + 1, MOD) % MOD;
}

// Stirling数第一类：s(n, k) 表示n个元素分成k个环的方案数
vector<vector<long long>> stirling1(int n) {
    vector<vector<long long>> s(n + 1, vector<long long>(n + 1, 0));
    s[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            s[i][j] = ((i - 1) * s[i-1][j] % MOD + s[i-1][j-1]) % MOD;
        }
    }

    return s;
}

// Stirling数第二类：S(n, k) 表示n个元素分成k个非空集合的方案数
vector<vector<long long>> stirling2(int n) {
    vector<vector<long long>> S(n + 1, vector<long long>(n + 1, 0));
    S[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            S[i][j] = (j * S[i-1][j] % MOD + S[i-1][j-1]) % MOD;
        }
    }

    return S;
}

// 容斥原理计算错排数
long long derangement(int n) {
    if (n == 0) return 1;
    if (n == 1) return 0;

    vector<long long> D(n + 1);
    D[0] = 1;
    D[1] = 0;

    for (int i = 2; i <= n; i++) {
        D[i] = (i - 1) * ((D[i-1] + D[i-2]) % MOD) % MOD;
    }

    return D[n];
}

// 使用示例
int main() {
    // 方法1：预处理方式
    CombinationMod comb(MAXN);

    cout << "Using precomputation:" << endl;
    cout << "C(10, 5) = " << comb.C(10, 5) << endl;
    cout << "C(100, 50) = " << comb.C(100, 50) << endl;
    cout << "P(10, 3) = " << comb.P(10, 3) << endl;

    // 方法2：Lucas定理
    cout << "\nUsing Lucas theorem:" << endl;
    long long p = 13;
    cout << "C(10, 5) mod " << p << " = " << lucas(10, 5, p) << endl;
    cout << "C(1000, 500) mod " << p << " = " << lucas(1000, 500, p) << endl;

    // 方法3：Pascal三角
    cout << "\nPascal's Triangle (first 11 rows):" << endl;
    auto pascal = pascalTriangle(10);
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= i; j++) {
            cout << pascal[i][j] << " ";
        }
        cout << endl;
    }

    // Catalan数
    cout << "\nCatalan numbers:" << endl;
    for (int i = 0; i <= 10; i++) {
        cout << "C_" << i << " = " << catalan(i, comb) << endl;
    }

    // 错排数
    cout << "\nDerangement numbers:" << endl;
    for (int i = 0; i <= 10; i++) {
        cout << "D(" << i << ") = " << derangement(i) << endl;
    }

    return 0;
}
