/*
 * 扩展欧几里得算法 (Extended Euclidean Algorithm)
 * 用途：求解 ax + by = gcd(a, b)，求模逆元，解线性同余方程
 * 时间复杂度：O(log min(a, b))
 */

#include <bits/stdc++.h>
using namespace std;

// 扩展欧几里得算法
// 返回gcd(a, b)，并通过引用返回x, y使得 ax + by = gcd(a, b)
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

// 求模逆元：求 a^(-1) mod m
// 即求 x 使得 ax ≡ 1 (mod m)
// 要求 gcd(a, m) = 1
long long modInverse(long long a, long long m) {
    long long x, y;
    long long g = extGCD(a, m, x, y);

    if (g != 1) {
        return -1;  // 模逆元不存在
    }

    return (x % m + m) % m;  // 确保返回正数
}

// 求解线性同余方程 ax ≡ b (mod m)
// 返回 {是否有解, 最小非负整数解, 通解数量}
tuple<bool, long long, long long> solveLinearCongruence(long long a, long long b, long long m) {
    long long x, y;
    long long g = extGCD(a, m, x, y);

    if (b % g != 0) {
        return {false, -1, 0};  // 无解
    }

    x = x * (b / g);
    long long mod = m / g;
    x = (x % mod + mod) % mod;  // 最小非负整数解

    // 通解形式：x = x0 + k * (m / g), k ∈ Z
    // 在 [0, m) 范围内有 g 个解

    return {true, x, g};
}

// 求解不定方程 ax + by = c
// 返回一组特解 (x0, y0) 和通解的系数
struct Solution {
    bool hasSolution;
    long long x0, y0;  // 特解
    long long dx, dy;  // 通解增量：x = x0 + k*dx, y = y0 + k*dy
};

Solution solveDiophantine(long long a, long long b, long long c) {
    Solution sol;
    long long x, y;
    long long g = extGCD(a, b, x, y);

    if (c % g != 0) {
        sol.hasSolution = false;
        return sol;
    }

    sol.hasSolution = true;
    sol.x0 = x * (c / g);
    sol.y0 = y * (c / g);
    sol.dx = b / g;
    sol.dy = -a / g;

    return sol;
}

// 求不定方程在特定范围内的解的数量
// ax + by = c, x ∈ [x1, x2], y ∈ [y1, y2]
long long countSolutionsInRange(long long a, long long b, long long c,
                                long long x1, long long x2,
                                long long y1, long long y2) {
    auto sol = solveDiophantine(a, b, c);
    if (!sol.hasSolution) return 0;

    // 计算k的范围
    // x = x0 + k * dx 在 [x1, x2] 范围内
    // y = y0 + k * dy 在 [y1, y2] 范围内

    long long kMin = LLONG_MIN, kMax = LLONG_MAX;

    // 从x的约束计算k的范围
    if (sol.dx > 0) {
        kMin = max(kMin, (long long)ceil((double)(x1 - sol.x0) / sol.dx));
        kMax = min(kMax, (long long)floor((double)(x2 - sol.x0) / sol.dx));
    } else if (sol.dx < 0) {
        kMin = max(kMin, (long long)ceil((double)(x2 - sol.x0) / sol.dx));
        kMax = min(kMax, (long long)floor((double)(x1 - sol.x0) / sol.dx));
    } else {
        if (sol.x0 < x1 || sol.x0 > x2) return 0;
    }

    // 从y的约束计算k的范围
    if (sol.dy > 0) {
        kMin = max(kMin, (long long)ceil((double)(y1 - sol.y0) / sol.dy));
        kMax = min(kMax, (long long)floor((double)(y2 - sol.y0) / sol.dy));
    } else if (sol.dy < 0) {
        kMin = max(kMin, (long long)ceil((double)(y2 - sol.y0) / sol.dy));
        kMax = min(kMax, (long long)floor((double)(y1 - sol.y0) / sol.dy));
    } else {
        if (sol.y0 < y1 || sol.y0 > y2) return 0;
    }

    if (kMin > kMax) return 0;
    return kMax - kMin + 1;
}

// 中国剩余定理（两个方程的情况）
// 求解：x ≡ a1 (mod m1) 且 x ≡ a2 (mod m2)
// 返回 {是否有解, 解x, 模数M}（通解为 x + k*M, k ∈ Z）
tuple<bool, long long, long long> crtTwo(long long a1, long long m1,
                                         long long a2, long long m2) {
    long long x, y;
    long long g = extGCD(m1, m2, x, y);

    if ((a2 - a1) % g != 0) {
        return {false, -1, -1};  // 无解
    }

    long long M = m1 / g * m2;  // lcm(m1, m2)
    long long k = (a2 - a1) / g;
    long long sol = (a1 + k * m1 % M * x % M) % M;
    sol = (sol % M + M) % M;

    return {true, sol, M};
}

// 使用示例
int main() {
    // 扩展欧几里得算法
    long long a = 35, b = 15;
    long long x, y;
    long long g = extGCD(a, b, x, y);
    cout << "Extended GCD:" << endl;
    cout << a << " * " << x << " + " << b << " * " << y << " = " << g << endl;

    // 模逆元
    long long num = 3, mod = 11;
    long long inv = modInverse(num, mod);
    if (inv != -1) {
        cout << "\nModular inverse of " << num << " mod " << mod << " = " << inv << endl;
        cout << "Verification: " << num << " * " << inv << " mod " << mod << " = "
             << (num * inv % mod) << endl;
    }

    // 线性同余方程
    auto [hasSol, sol, numSol] = solveLinearCongruence(6, 9, 15);
    if (hasSol) {
        cout << "\nSolution of 6x ≡ 9 (mod 15):" << endl;
        cout << "x = " << sol << " (and " << numSol << " solutions in total)" << endl;
    }

    // 不定方程
    auto diophantine = solveDiophantine(5, 3, 7);
    if (diophantine.hasSolution) {
        cout << "\nSolutions of 5x + 3y = 7:" << endl;
        cout << "Particular solution: x = " << diophantine.x0
             << ", y = " << diophantine.y0 << endl;
        cout << "General solution: x = " << diophantine.x0 << " + " << diophantine.dx << "k" << endl;
        cout << "                  y = " << diophantine.y0 << " + " << diophantine.dy << "k" << endl;

        // 验证
        cout << "Verification: 5*" << diophantine.x0 << " + 3*" << diophantine.y0
             << " = " << (5 * diophantine.x0 + 3 * diophantine.y0) << endl;
    }

    // 中国剩余定理（两个方程）
    auto [has, x_crt, M] = crtTwo(2, 5, 3, 7);
    if (has) {
        cout << "\nCRT solution:" << endl;
        cout << "x ≡ 2 (mod 5) and x ≡ 3 (mod 7)" << endl;
        cout << "x = " << x_crt << " (mod " << M << ")" << endl;
    }

    return 0;
}
