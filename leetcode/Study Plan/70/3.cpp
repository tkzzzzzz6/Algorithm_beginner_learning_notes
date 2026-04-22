// 通项公式
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        double sqrt5 = sqrt(5);
        double fibn = pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1);
        return (int)round(fibn / sqrt5);
    }
};



int main()
{
    Solution s;
    int n = 2; // 爬楼梯的阶数
    cout << s.climbStairs(n); // 输出爬n阶楼梯的方法数
    return 0;
}