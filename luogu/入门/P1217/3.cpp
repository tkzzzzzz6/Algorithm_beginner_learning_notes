// 超时
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool isPalindrome(int n)
{
    int original = n;
    int reversed = 0;
    while(n > 0){
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return original == reversed;
}

int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        if (isPalindrome(i) && isPrime(i))
        {
            cout << i << endl;
        }
    }
    return 0;
}