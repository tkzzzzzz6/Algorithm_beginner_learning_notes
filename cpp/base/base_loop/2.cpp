#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <vector>

// 多重循环的顺序可以类比时钟的顺序
using namespace std;

int n, m;
int main()
{
    cin >> n;
    int max = 0, x = 0;
    --n;
    cin >> max;
    while (n--)
    {
        cin >> x;
        if (max < x)
            max = x;
    }
    cout << max << endl;

    return 0;
}