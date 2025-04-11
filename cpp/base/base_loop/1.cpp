#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <vector>

// 多重循环的顺序可以类比时钟的顺序
using namespace std;

int a, sum = 0;
int main()
{
    cin >> a;
    while (a != 0)
    {
        sum += a % 10;
        a /= 10;
    }
    cout << sum << endl;
    return 0;
}