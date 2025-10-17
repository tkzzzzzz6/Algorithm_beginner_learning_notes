#include <stdio.h>
void swap(int m, int n)
{
    int z;
    z = m;
    m = n;
    n = z;
    printf("形参：m=%d,n=%d", m, n);
}
int main()
{
    int m = 3, n = 5;
    swap(m, n);
    printf("实参：m=%d,n=%d", m, n);
}
