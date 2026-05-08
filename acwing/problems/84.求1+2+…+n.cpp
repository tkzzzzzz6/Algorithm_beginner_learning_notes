/*
 * @acwing app=acwing.cn id=80 lang=C++
 *
 * 84. 求1+2+…+n
 */

// @acwing code start

class Solution {
   public:
    int getSum(int n) {
        int res = n;
        return ((n > 0) && (res += getSum(n - 1)), res);
    }
};
// @acwing code end
