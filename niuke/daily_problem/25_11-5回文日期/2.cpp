#include <bits/stdc++.h>
using namespace std;
int main()
{
    int st, ed, ans = 0;
    int up[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cin >> st >> ed;
    for (int i = 1; i <= 12; i++)
    {
        for (int j = 1; j <= up[i]; j++)
        {

            // 回文日期 = (日期倒置)(月份倒置)(月份)(日期) 
            // = D₂D₁M₂M₁ + M₁M₂ + D₁D₂ = YYYY + MM + DD
             int y = j % 10 * 1e7   // 日期个位 → 年份千万位
                                                                                                          + j / 10 * 1e6 // 日期十位 → 年份百万位
                                                                                                          + i % 10 * 1e5 // 月份个位 → 年份十万位
                                                                                                          + i / 10 * 1e4 // 月份十位 → 年份万位
                                                                                                          + i * 1e2      // 完整月份 → 百十位
                                                                                                          + j;           // 完整日期 → 个十位
            // 构建对应的日期的序列号,然后判断是否在范围内,应为是8为整数,可以使用int存储,不会溢出
            if (y >= st && y <= ed)
                ans++;
        }
    }
    cout << ans;
    return 0;
}
