/*
 * @acwing app=acwing.cn id=78 lang=C++
 *
 * 82. 圆圈中最后剩下的数字
 */

// @acwing code start

class Solution {
   public:
    int lastRemaining(int n, int m) {
        if (n == 1)
            return 0;
        return (lastRemaining(n - 1, m) + m) % n;
    }
};
// @acwing code end
