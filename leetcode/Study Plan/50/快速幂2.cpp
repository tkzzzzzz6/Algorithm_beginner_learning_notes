#include <iostream>
// 快速幂
// 递归分治法
using namespace std;

class Solution
{
public:
    double powHelper(double x, long long n)
    {
        double res = 1.0;
        double contribute_x = x;
        while(n){
            if(n % 2 == 1){
                res *= contribute_x;
            }
            n /= 2;
            contribute_x *= contribute_x;
        }
        return res;
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