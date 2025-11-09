#include <stdio.h>
int max(int x, int y)
{
    int z;
    if (x > y)
        z = x;
    else
        z = y;
    return x,y;
}

int main()
{
    int max(int x, int y);
    int a, b, c;
    printf("please enter two numbers:");
    scanf("%d,%d", &a, &b);
    c = max(a, b);
    printf("max is c=%d\n", c);
}
