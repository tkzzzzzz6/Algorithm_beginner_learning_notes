#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <vector>

// 多重循环的顺序可以类比时钟的顺序
using namespace std;

void contiguousSegment(long long M)
{
    long long L = 1, R = 2;
    long long target = 0;
    for (int L = 1; L < M / 2; ++L)
    {
        for (; R <= M; ++R)
        {
            target = (L + R) * (R - L + 1);
            if (target > 2 * M)
                break;
            if (target == 2 * M)
            {
                while (L < R)
                {
                    cout << L << '+';
                    L++;
                }
                cout << R << endl;
            }
        }
    }
}

long long M;
int main()
{
    cin >> M;
    contiguousSegment(M);
    return 0;
}