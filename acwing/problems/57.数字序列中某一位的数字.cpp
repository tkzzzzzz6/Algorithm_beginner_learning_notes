/*
 * @acwing app=acwing.cn id=52 lang=C++
 *
 * 57. 数字序列中某一位的数字
 */

// @acwing code start

class Solution {
   public:
    int digitAtIndex(int n) {
        if (!n)
            return 0;
        long long i = 1, s = 9,
                  base = 1; // i 表示从什么开始枚举,s 表示对应位数的数的数量,base
                            // 表示对应位数从什么数开始枚举

        // 确定是第几位数
        while (n > i * s) {
            n -= i * s;
            ++i;
            s *= 10;
            base *= 10;
        }

        int number = base + (n + i - 1) / i - 1; // 向上取整
        int r = n % i ? n % i : i;

        for (int j = 0; j < i - r; ++j) {
            number /= 10;
        }

        return number % 10;
    }
};
// @acwing code end
