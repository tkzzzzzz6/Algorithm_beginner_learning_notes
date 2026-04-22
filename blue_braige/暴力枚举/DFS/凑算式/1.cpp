#include <bits/stdc++.h>
using namespace std;

bool st[15];      // 标记数组，标记数字是否已经被使用过
int num[15], ans; // 数组num存储排列的数字，ans记录满足条件的排列数量

// 深度优先搜索函数，用于生成排列并判断是否满足条件
void dfs(int n)
{
    // 如果已经生成了一个排列
    if (n == 10)
    {
        // 计算出数字x和y
        int x = num[4] * 100 + num[5] * 10 + num[6];
        int y = num[7] * 100 + num[8] * 10 + num[9];

        // 判断是否满足条件
        if (num[1] * num[3] * y + num[2] * y + x * num[3] == 10 * num[3] * y)
        {
            ans++; // 满足条件的排列数量加一
            return;
        }
    }

    // 遍历可能的数字
    for (int i = 1; i <= 9; ++i)
    {
        // 如果数字已经被使用过，则跳过
        if (st[i])
            continue;

        st[i] = 1;  // 标记当前数字已经被使用
        num[n] = i; // 将当前数字加入排列中
        dfs(n + 1); // 递归生成下一个位置的数字
        st[i] = 0;  // 回溯，撤销当前数字的使用标记
    }
}

int main()
{
    dfs(1);      // 从第一个位置开始生成排列
    cout << ans; // 输出满足条件的排列数量
    return 0;
}