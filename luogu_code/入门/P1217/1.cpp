#include <bits/stdc++.h>
using namespace std;
int l, r;
bool check1(int x) // 检查位数
{
    if ((1000 <= x && x <= 9999) || (100000 <= x && x <= 999999))
        return 0; // 不知道&&和||优先级的可以打个括号
    return 1;
}
bool check2(int x) // 检查是否回文
{
    int a[20], flag = 1; // 反正开得下，多开点
    while (x > 0)
    {
        a[flag] = x % 10;
        x /= 10;
        flag++;
    }
    for (int i = 1; i <= flag / 2; i++)
        if (a[i] != a[flag - i])
            return 0; // 不符合回文
    return 1;
}
bool check3(int x) // 检查是否为质数
{
    if (x == 2)
        return 1;
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return 0;
    return 1;
}
int main()
{
    scanf("%d %d", &l, &r);
    if (l == 2)
        printf("2\n"); // 一定要注意2！！！
    if (l % 2 == 0)
        l++;
    r = min(9999999, r);               // 再大的数都不可能是回文质数
    for (int i = l; i <= r; i = i + 2) // 枚举每一个奇数
    {
        if (check1(i) == 0)
            continue;
        if (check2(i) == 0)
            continue;
        if (check3(i) == 0)
            continue;
        printf("%d\n", i); // printf会比cout快很多
    }
    return 0;
}