#include <cmath>

// 使用数学公式求解x的算术平方根
// 利用公式：sqrt(x) = e^(0.5 * ln(x))
class Solution
{
public:
    int mySqrt(int x)
    {
        // 处理特殊情况：x为0时直接返回0
        if(x == 0)
            return 0;
        // 使用exp和log函数计算平方根
        // exp(0.5 * log(x)) = e^(0.5 * ln(x)) = sqrt(x)
        int res = exp(0.5 * log(x));
        return (long long)(res + 1) * (res + 1) <= x ? res + 1 : res;
    }
};