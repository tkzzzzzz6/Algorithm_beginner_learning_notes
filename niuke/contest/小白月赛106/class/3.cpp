#include <stdio.h>
void swap(int m, int n)
{
    int z;
    z = m;
    m = n;
    n = z;
    printf("βΣm=%d,n=%d", m, n);
}
int main()
{
    int m = 3, n = 5;
    swap(m, n);
    printf("ʵΣm=%d,n=%d", m, n);
}
