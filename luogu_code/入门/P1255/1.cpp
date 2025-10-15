#include <cstdio> // 引入标准输入输出库
#include <algorithm> // 引入算法库
#include <iostream> // 引入输入输出流库
#include <cstring> // 引入字符串处理库
using namespace std; // 使用标准命名空间

int n, len = 1, f[5003][5003]; // f[k][i]表示第k阶台阶所对应的走法数，len用于记录有效位数

// 高精度加法函数，k表示当前阶数
void hp(int k)                 
{
    int i; // 循环变量
    // 计算第k阶的走法数，使用前两阶的走法数
    for (i = 1; i <= len; i++)
        f[k][i] = f[k - 1][i] + f[k - 2][i]; // 套用公式，f[k] = f[k-1] + f[k-2]
    
    // 处理进位
    for (i = 1; i <= len; i++)               
        if (f[k][i] >= 10) // 如果当前位数大于等于10
        {
            f[k][i + 1] += f[k][i] / 10; // 进位到下一位
            f[k][i] = f[k][i] % 10; // 当前位数取余
            if (f[k][len + 1]) // 如果有新的高位产生
                len++; // 更新有效位数
        }
}

int main()
{
    int i; // 循环变量
    scanf("%d", &n); // 输入阶数n
    f[1][1] = 1; // 初始化第1阶的走法数为1
    f[2][1] = 2; // 初始化第2阶的走法数为2
    // 从第3阶开始计算，避免越界
    for (i = 3; i <= n; i++) 
        hp(i); // 调用高精度加法函数计算走法数
    
    // 逆序输出结果
    for (i = len; i >= 1; i--) 
        printf("%d", f[n][i]); // 输出第n阶的走法数
    return 0; // 返回0表示程序正常结束
}