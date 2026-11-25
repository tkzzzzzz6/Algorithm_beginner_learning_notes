/*
 * @Author: tkzzzzzz6
 * @Date: 2026-11-25 10:16:33
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-11-25 10:38:58
 */
// 快速幂: base^power, O(log power)
// 注意: power = 0 时返回 1; 溢出请用带模版本或 __int128
long long fast_power(long long base, long long power) {
    long long res = 1;
    while (power > 0) {
        if (power & 1) res = res * base;
        base = base * base;
        power >>= 1;
    }
    return res;
}

// 带模快速幂: base^power % mod
// 若 mod 接近 1e18 级别, 将乘法改为 (__int128)a * b % mod 防溢出
long long fast_power(long long base, long long power, long long mod) {
    long long res = 1 % mod;
    base %= mod;
    while (power > 0) {
        if (power & 1) res = res * base % mod;
        base = base * base % mod;
        power >>= 1;
    }
    return res;
}
