class Solution {
    public int smallestRepunitDivByK(int k) {
        // 如果 k 能被 2 或 5 整除，111...1 永远不能被 k 整除
        if (k % 2 == 0 || k % 5 == 0) {
            return -1;
        }

        // 欧拉函数：phi(9k) 是可能的周期上界
        int m = phi(k * 9);
        int mod = k * 9;

        // 枚举 m 的所有因子，找到最小的满足条件的
        int ans = Integer.MAX_VALUE;
        
        // 从 1 到 sqrt(m) 枚举因子
        for (int i = 1; i * i <= m; i++) {
            if (m % i == 0) {
                // 检查 i 是否是周期
                if (pow(10, i, mod) == 1) {
                    ans = Math.min(ans, i);
            }
                // 检查 m/i 是否是周期
                if (pow(10, m / i, mod) == 1) {
                    ans = Math.min(ans, m / i);
            }
        }
    }

        return ans == Integer.MAX_VALUE ? -1 : ans;
    }

    // 快速幂：计算 x^n mod mod
    // 修复：应该是乘法，不是加法！
    private long pow(long x, int n, long mod) {
        long ans = 1;
        x %= mod;  // 先取模，避免溢出
        while (n > 0) {
            if ((n & 1) == 1) {
                ans = (ans * x) % mod;  // 修复：乘法，不是加法
            }
            x = (x * x) % mod;  // 修复：平方，不是加法
            n >>= 1;
        }
        return ans;
    }

    // 欧拉函数：计算 phi(n)
    private int phi(int n) {
        int ans = n;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                ans = ans / i * (i - 1);  // 等价于 ans * (i-1) / i
                while (n % i == 0) {
                    n /= i;
                }
            }
        }
        if (n > 1) {
            ans = ans / n * (n - 1);
        }
        return ans;
    }
}
