/*
 * 最大公约数 (GCD) 和 最小公倍数 (LCM)
 * 用途：数论基础运算
 * 时间复杂度：O(log min(a, b))
 */

#include <bits/stdc++.h>
using namespace std;

// 欧几里得算法求GCD
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 递归版本GCD
long long gcdRecursive(long long a, long long b) {
    return b == 0 ? a : gcdRecursive(b, a % b);
}

// C++17的内置gcd（推荐使用）
// long long g = __gcd(a, b);  // C++14及之前
// long long g = std::gcd(a, b);  // C++17及以后

// 最小公倍数
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;  // 防止溢出，先除后乘
}

// 多个数的GCD
long long gcdMultiple(vector<long long>& nums) {
    long long result = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        result = gcd(result, nums[i]);
        if (result == 1) break;  // 优化：如果已经是1，可以提前退出
    }
    return result;
}

// 多个数的LCM
long long lcmMultiple(vector<long long>& nums) {
    long long result = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        result = lcm(result, nums[i]);
    }
    return result;
}

// 扩展欧几里得算法（求ax + by = gcd(a, b)的一组解）
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

// 求解线性同余方程 ax ≡ b (mod m) 的解
// 返回 {是否有解, 最小非负整数解}
pair<bool, long long> linearCongruence(long long a, long long b, long long m) {
    long long x, y;
    long long g = extGCD(a, m, x, y);

    if (b % g != 0) {
        return {false, -1};  // 无解
    }

    x = x * (b / g);
    long long mod = m / g;
    x = (x % mod + mod) % mod;  // 最小非负整数解

    return {true, x};
}

// 中国剩余定理（CRT）
// 求解同余方程组：x ≡ a[i] (mod m[i])
// 要求所有m[i]两两互质
long long crt(vector<long long>& a, vector<long long>& m) {
    int n = a.size();
    long long M = 1;
    for (int i = 0; i < n; i++) {
        M *= m[i];
    }

    long long x = 0;
    for (int i = 0; i < n; i++) {
        long long Mi = M / m[i];
        long long xi, yi;
        extGCD(Mi, m[i], xi, yi);
        x = (x + a[i] * Mi % M * xi % M) % M;
    }

    return (x % M + M) % M;
}

// 更相减损术（辗转相减法）
long long gcdSubtraction(long long a, long long b) {
    while (a != b) {
        if (a > b) a -= b;
        else b -= a;
    }
    return a;
}

// Stein算法（二进制GCD算法，避免取模运算）
long long gcdStein(long long a, long long b) {
    if (a == 0) return b;
    if (b == 0) return a;

    int shift = 0;
    while (((a | b) & 1) == 0) {
        a >>= 1;
        b >>= 1;
        shift++;
    }

    while ((a & 1) == 0) a >>= 1;

    do {
        while ((b & 1) == 0) b >>= 1;
        if (a > b) swap(a, b);
        b -= a;
    } while (b != 0);

    return a << shift;
}

// 计算a^b mod m的GCD性质
// gcd(a^n - 1, a^m - 1) = a^gcd(n,m) - 1
long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

// 使用示例
int main() {
    long long a = 48, b = 18;

    cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b) << endl;
    cout << "LCM(" << a << ", " << b << ") = " << lcm(a, b) << endl;

    // 多个数的GCD和LCM
    vector<long long> nums = {12, 18, 24, 36};
    cout << "\nGCD of multiple numbers: " << gcdMultiple(nums) << endl;
    cout << "LCM of multiple numbers: " << lcmMultiple(nums) << endl;

    // 扩展欧几里得算法
    long long x, y;
    long long g = extGCD(a, b, x, y);
    cout << "\nExtended GCD:" << endl;
    cout << a << " * " << x << " + " << b << " * " << y << " = " << g << endl;

    // 线性同余方程
    auto [hasSol, sol] = linearCongruence(3, 6, 9);
    if (hasSol) {
        cout << "\nSolution of 3x ≡ 6 (mod 9): x = " << sol << endl;
    }

    // 中国剩余定理
    vector<long long> remainders = {2, 3, 2};
    vector<long long> moduli = {3, 5, 7};
    cout << "\nCRT solution: " << crt(remainders, moduli) << endl;

    return 0;
}
