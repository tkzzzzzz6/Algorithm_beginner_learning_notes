/*
 * 模逆元 (Modular Inverse)
 * 用途：求 x 使得 (a * x) ≡ 1 (mod m)
 * 条件：gcd(a, m) = 1
 * 应用：模运算下的除法、组合数计算
 */

#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

// 方法1：扩展欧几里得算法（适用于任意模数）
long long extGCD(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = extGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

long long modInverseExtGCD(long long a, long long m) {
    long long x, y;
    long long g = extGCD(a, m, x, y);

    if (g != 1) {
        return -1;  // 模逆元不存在
    }

    return (x % m + m) % m;
}

// 方法2：费马小定理（仅适用于m为素数）
// a^(m-1) ≡ 1 (mod m)，因此 a^(m-2) ≡ a^(-1) (mod m)
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

long long modInverseFermat(long long a, long long m) {
    // 要求m是素数且gcd(a, m) = 1
    return power(a, m - 2, m);
}

// 方法3：欧拉定理（适用于gcd(a, m) = 1）
// a^φ(m) ≡ 1 (mod m)，因此 a^(φ(m)-1) ≡ a^(-1) (mod m)
long long phi(long long n) {
    long long result = n;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            result -= result / i;
        }
    }
    if (n > 1) result -= result / n;
    return result;
}

long long modInverseEuler(long long a, long long m) {
    return power(a, phi(m) - 1, m);
}

// 方法4：线性预处理1到n的所有模逆元
// inv[i] = (m - m/i) * inv[m % i] % m
vector<long long> linearInverse(int n, long long m) {
    vector<long long> inv(n + 1);
    inv[1] = 1;

    for (int i = 2; i <= n; i++) {
        inv[i] = (m - m / i) * inv[m % i] % m;
    }

    return inv;
}

// 应用1：模运算下的除法
// (a / b) mod m = (a * b^(-1)) mod m
long long modDivision(long long a, long long b, long long m) {
    long long inv = modInverseFermat(b, m);
    return a * inv % m;
}

// 应用2：求解线性同余方程 ax ≡ b (mod m)
long long solveLinearCongruence(long long a, long long b, long long m) {
    long long inv = modInverseExtGCD(a, m);
    if (inv == -1) return -1;  // 无解
    return b * inv % m;
}

// 应用3：阶乘的模逆元（用于组合数计算）
class FactorialInverse {
private:
    vector<long long> fact, invFact;
    int maxN;
    long long mod;

public:
    FactorialInverse(int n, long long m) : maxN(n), mod(m) {
        fact.resize(maxN + 1);
        invFact.resize(maxN + 1);

        fact[0] = 1;
        for (int i = 1; i <= maxN; i++) {
            fact[i] = fact[i-1] * i % mod;
        }

        invFact[maxN] = modInverseFermat(fact[maxN], mod);
        for (int i = maxN - 1; i >= 0; i--) {
            invFact[i] = invFact[i+1] * (i+1) % mod;
        }
    }

    long long C(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % mod * invFact[n-r] % mod;
    }
};

// Wilson定理：(p-1)! ≡ -1 (mod p) 当且仅当p是素数
bool isPrimeWilson(long long p) {
    if (p <= 1) return false;
    if (p <= 3) return true;

    long long fact = 1;
    for (long long i = 2; i < p; i++) {
        fact = fact * i % p;
    }

    return fact == p - 1;
}

// 批量求逆元（使用前缀积的方法）
vector<long long> batchInverse(vector<long long>& a, long long m) {
    int n = a.size();
    vector<long long> prefix(n + 1, 1);
    vector<long long> inv(n);

    // 计算前缀积
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] * a[i] % m;
    }

    // 求前缀积的逆元
    long long allInv = modInverseFermat(prefix[n], m);

    // 倒推每个数的逆元
    for (int i = n - 1; i >= 0; i--) {
        inv[i] = allInv * prefix[i] % m;
        allInv = allInv * a[i] % m;
    }

    return inv;
}

// 乘法逆元表（预处理1到n的逆元）
class InverseTable {
private:
    vector<long long> inv;
    long long mod;

public:
    InverseTable(int n, long long m) : mod(m) {
        inv.resize(n + 1);
        inv[1] = 1;

        for (int i = 2; i <= n; i++) {
            inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        }
    }

    long long get(int i) {
        return inv[i];
    }
};

// 使用示例
int main() {
    long long a = 5, m = 11;

    // 方法1：扩展欧几里得
    cout << "Using Extended GCD:" << endl;
    long long inv1 = modInverseExtGCD(a, m);
    cout << "Inverse of " << a << " mod " << m << " = " << inv1 << endl;
    cout << "Verification: " << a << " * " << inv1 << " mod " << m
         << " = " << (a * inv1 % m) << endl;

    // 方法2：费马小定理
    cout << "\nUsing Fermat's Little Theorem:" << endl;
    long long inv2 = modInverseFermat(a, MOD);
    cout << "Inverse of " << a << " mod " << MOD << " = " << inv2 << endl;
    cout << "Verification: " << a << " * " << inv2 << " mod " << MOD
         << " = " << (a * inv2 % MOD) << endl;

    // 线性预处理
    cout << "\nLinear preprocessing (1 to 10):" << endl;
    auto invTable = linearInverse(10, MOD);
    for (int i = 1; i <= 10; i++) {
        cout << "inv[" << i << "] = " << invTable[i] << endl;
    }

    // 模除法
    cout << "\nModular division:" << endl;
    long long numerator = 20, denominator = 3;
    long long result = modDivision(numerator, denominator, MOD);
    cout << numerator << " / " << denominator << " mod " << MOD
         << " = " << result << endl;

    // 组合数计算
    cout << "\nCombination using factorial inverse:" << endl;
    FactorialInverse factInv(1000, MOD);
    cout << "C(10, 5) = " << factInv.C(10, 5) << endl;
    cout << "C(100, 50) = " << factInv.C(100, 50) << endl;

    // 批量求逆元
    cout << "\nBatch inverse:" << endl;
    vector<long long> numbers = {2, 3, 5, 7, 11};
    auto batchInv = batchInverse(numbers, MOD);
    for (int i = 0; i < numbers.size(); i++) {
        cout << "Inverse of " << numbers[i] << " = " << batchInv[i] << endl;
    }

    // 逆元表
    cout << "\nInverse table:" << endl;
    InverseTable invTab(20, MOD);
    for (int i = 1; i <= 20; i++) {
        cout << "inv(" << i << ") = " << invTab.get(i) << endl;
    }

    return 0;
}
