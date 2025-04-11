#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <vector>

// 多重循环的顺序可以类比时钟的顺序
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int n;
int main()
{
    cin >> n;
    if (isPrime(n))
        cout << "Yes";
    else
    {
        printf("No");
    }
    return 0;
}