#include <bits/stdc++.h>
using namespace std;

// 数字对应的笔画数
const int cnt[10] = {13, 1, 2, 3, 5, 4, 4, 2, 2, 2};

// 判断是否为闰年
bool leap(int year)
{
    // 闰年条件：能被400整除，或者能被4整除但不能被100整除
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

// 获取某年某月的最大天数
int maxdays(int year, int month)
{
    // 大月有31天
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;
    // 小月有30天
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    // 二月根据是否为闰年决定天数
    return leap(year) ? 29 : 28;
}

int main()
{
    int ans = 0; // 记录符合条件的天数
    int year = 2000, month = 1, day = 1; // 从2000年1月1日开始

    while (1)
    {
        // 到达2024年4月14日时停止
        if (year == 2024 && month == 4 && day == 14)
            break;

        int tot = 0; // 记录当前日期的总笔画数
        // 计算年份的笔画数
        tot += cnt[year / 1000] + cnt[year / 100 % 10] + cnt[year / 10 % 10] + cnt[year % 10];
        // 计算月份的笔画数
        tot += cnt[month / 10] + cnt[month % 10];
        // 计算日期的笔画数
        tot += cnt[day / 10] + cnt[day % 10];

        // 如果总笔画数大于50，计数加1
        if (tot > 50)
            ans++;

        // 日期递增
        if (day < maxdays(year, month))
            day++;
        else
        {
            day = 1; // 重置为1号
            if (month < 12)
                month++; // 月份递增
            else
            {
                year++; // 年份递增
                month = 1; // 重置为1月
            }
        }
    }

    // 输出符合条件的天数
    cout << ans;
    return 0;
}
