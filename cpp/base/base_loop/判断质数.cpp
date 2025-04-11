#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <vector>

using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; ++i)
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
    {
        cout << "Yes";
    }
    else
    {
        printf("No");
    }
    return 0;
}