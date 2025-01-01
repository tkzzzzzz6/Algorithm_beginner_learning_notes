#include <stdio.h>

int main()
{
    int a;
    printf("请输入末位不是零的任意三位十进制整数");
    scanf("%d", &a);
    while (a % 10 == 0)
    {
        printf("输入错误,请重新输入");
        scanf("%d", &a);
    }
    int a1, a2, a3;
    a3 = a / 100;
    a2 = a / 10 % 10;
    a1 = a % 10;
    int sum = a1*100 + a2 * 10 + a3;
    printf("%d", sum);
}