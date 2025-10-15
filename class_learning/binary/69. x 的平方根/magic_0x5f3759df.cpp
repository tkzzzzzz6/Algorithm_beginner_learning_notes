
// 使用快速平方根算法（Fast Inverse Square Root）的变体
// 0x5f3759df 是一个魔法数字，用于快速估计平方根
class Solution
{
public:
    int mySqrt(int x)
    {
        // 使用long类型避免整数溢出
        long x0 = x;
        // 使用魔法数字进行快速估计
        // x0>>1 相当于除以2，用于快速估计
        x0 = 0x5f3759df - (x0>>1);
        // 使用牛顿迭代法进行精确化
        // 迭代公式：x = (x + n/x) / 2
        while (x0 * x0 > x)
        {
            x0 = (x0 + x / x0) / 2;
        }
        return (int)x0;
    }
};