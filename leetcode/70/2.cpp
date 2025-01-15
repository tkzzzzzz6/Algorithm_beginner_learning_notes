// 矩阵快速幂
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // 矩阵乘法函数，计算两个2x2矩阵a和b的乘积
    vector<vector<long long>> multiply(vector<vector<long long>> &a, vector<vector<long long>> &b)
    {
        vector<vector<long long>> c(2, vector<long long>(2)); // 初始化结果矩阵c
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                // 计算c[i][j]的值
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
            }
        }
        return c; // 返回结果矩阵
    }

    // 矩阵快速幂函数，计算矩阵a的n次幂
    vector<vector<long long>> matrixPow(vector<vector<long long>> a, int n)
    {
        vector<vector<long long>> ret = {{1, 0}, {0, 1}}; // 初始化单位矩阵ret
        while (n > 0)
        {
            if ((n & 1) == 1) // 如果n是奇数
            {
                ret = multiply(ret, a); // 将当前矩阵a乘到结果矩阵ret上
            }
            n >>= 1; // n右移一位，相当于n除以2
            a = multiply(a, a); // 矩阵a自乘
        }
        return ret; // 返回结果矩阵
    }

    // 计算爬楼梯的方法数
    int climbStairs(int n)
    {
        vector<vector<long long>> ret = {{1, 1}, {1, 0}}; // 初始化转移矩阵
        vector<vector<long long>> res = matrixPow(ret, n); // 计算转移矩阵的n次幂
        return res[0][0]; // 返回结果，即爬n阶楼梯的方法数
    }
};

int main()
{
    Solution s;
    int n = 2; // 爬楼梯的阶数
    cout << s.climbStairs(n); // 输出爬n阶楼梯的方法数
    return 0;
}