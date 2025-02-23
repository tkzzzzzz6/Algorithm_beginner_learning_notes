#include <stdio.h>
bool is_prime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int a = 0;
    scanf("%d", &a);
    if (is_prime(a))
        printf("%d是素数\n", a);
    else
        printf("%d不是素数\n", a);
}
