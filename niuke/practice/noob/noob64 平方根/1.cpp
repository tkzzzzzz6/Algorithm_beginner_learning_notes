#include<cmath>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 求非负整数 n 的平方根
     * @param n int整型 你需要求 n 的平方根
     * @return double浮点型
     */
    double findSqrt(int n) {
        // write code here
        if(n == 0 || n == 1)return n;
        if(n < 0)return -1;
        return sqrt(static_cast<double>(n));
    }
};
