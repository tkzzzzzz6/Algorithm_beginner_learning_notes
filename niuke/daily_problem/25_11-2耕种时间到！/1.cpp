#include <iostream>
using namespace std;

// 题意（简述）：
// 给定 n 颗种子的初始等级 a[i]。每轮操作：
//   1) 等级 a[i] 变为 ceil(a[i] / 3)（用 (a[i] + 2) / 3 实现向上取整）
//   2) 对应种子数量 s[i] 翻倍
// 问：在所有轮次（包括初始时刻）中，等级恰为 x 的种子数量之最大值。

int n;         // 种子数量
int a[100010]; // a[i]：第 i 颗种子的当前等级
int s[100010]; // s[i]：第 i 颗种子对应的数量（每轮翻倍），初始化为 1
int x;         // 目标等级
int main()
{
    cin >> n; // 读入种子数量
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        s[i] = 1; // 初始每颗种子数量为 1
    }
    cin >> x;              // 目标等级
    long long int ans = 0; // 历史最大“等级为 x 的种子数量”
    for (int i = 1; i <= n; ++i)
    { // 统计初始时刻等级为 x 的种子数量
        if (a[i] == x)
        {
            ans += s[i];
        }
    }
    int t; // 标记：本轮结束后是否仍存在等级 > x 的种子（决定是否继续模拟）
    do
    { // 模拟一轮种植（等级衰减且数量翻倍）
        t = 0;
        long long res = 0; // 记录本轮“等级恰为 x”的种子数量总和
        for (int i = 1; i <= n; ++i)
        {
            a[i] = (a[i] + 2) / 3; // 等级变为 ceil(a[i]/3)
            s[i] *= 2;             // 数量翻倍
            if (a[i] > x)
            {
                t = 1; // 仍有等级大于 x，需要继续下一轮
            }
            if (a[i] == x)
            {
                res += s[i]; // 累计本轮等级为 x 的数量
            }
        }
        ans = max(res, ans); // 维护历史最大值
    } while (t);
    cout << ans << endl; // 输出答案
}