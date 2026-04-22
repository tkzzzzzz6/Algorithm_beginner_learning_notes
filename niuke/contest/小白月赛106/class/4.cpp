#include <stdio.h>
void swap(int *p1, int *p2)
{
    int *t;
    *t = *p1;
    *p1 = *p2;
    *p2 = *t;
}

int main()
{
    int a, b, *p1, *p2;
    scanf("%d,%d", &a, &b);
    p1 = &a;
    p2 = &b;
    swap(p1, p2);
    printf("a=%d,b=%d\n", a, b);
    printf("*p1=%d,*p2=%d", *p1, *p2);
}
