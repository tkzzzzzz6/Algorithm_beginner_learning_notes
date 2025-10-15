#include <iostream>
// 快速幂
// 递归分治法
using namespace std;

class Solution
{
public:
    double powHelper(double x, int n)
    {
        if (n == 0)
            return 1.0;
        double half = powHelper(x, n / 2);
        return n % 2 == 0 ? half * half : half * half * x;
    }

    double myPow(double x, int n)
    {
        if (n == 0 || x == 1)
            return 1.0;
        long long N = n;
        if (N < 0)
            return 1.0 / powHelper(x, -N);
        return powHelper(x, N);
    }
};

int main()
{
    Solution s;
    cout << (s.myPow(2.00000, 10) == 1024);
    return 0;
}