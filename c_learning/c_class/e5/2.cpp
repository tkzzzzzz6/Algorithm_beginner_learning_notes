// 包含两种I/O库，可以使用任一种输入输出方式
#include <stdio.h>
#include <iostream>
using namespace std;

void RearrangeNumber(int n, int &max, int &min)
{
    int n1, n2, n3;

    n1 = n / 100;
    n2 = (n / 10) % 10;
    n3 = n % 10;

    // 比较n1,n2,n3的大小
    if (n1 <= n2 && n1 <= n3)
    {
        if (n2 <= n3)
        {
            max = n3 * 100 + n2 * 10 + n1;
            min = n1 * 100 + n2 * 10 + n3;
        }
        else
        {
            max = n2 * 100 + n3 * 10 + n1;
            min = n1 * 100 + n3 * 10 + n2;
        }
    }
    else if (n2 <= n1 && n2 <= n3)
    {
        if (n1 <= n3)
        {
            max = n3 * 100 + n1 * 10 + n2;
            min = n2 * 100 + n1 * 10 + n3;
        }
        else
        {
            max = n1 * 100 + n3 * 10 + n2;
            min = n2 * 100 + n3 * 10 + n1;
        }
    }
    else
    {
        if (n1 <= n2)
        {
            max = n2 * 100 + n1 * 10 + n3;
            min = n3 * 100 + n1 * 10 + n2;
        }
        else
        {
            max = n1 * 100 + n2 * 10 + n3;
            min = n3 * 100 + n2 * 10 + n1;
        }
    }
}

int main()
{
    // 请在此添加代码，输出整数进入黑洞过程
    /********** Begin *********/
    // n-输入的数，m-重排后的数
    int n, max, min;
    // 请在此添加代码，输入一个小于1000的正整数，重排出最大的数存入m中
    /********** Begin *********/
    scanf("%d", &n);
    RearrangeNumber(n, max, min);

    printf("1:%d-%d=%d\n", max, min, max - min);
    int cnt = 2;
    while (max - min != 495)
    {
        RearrangeNumber(max - min, max, min);
        printf("%d:%d-%d=%d\n", cnt, max, min, max - min);
        cnt++;
    }

    /********** End **********/
    return 0;
}