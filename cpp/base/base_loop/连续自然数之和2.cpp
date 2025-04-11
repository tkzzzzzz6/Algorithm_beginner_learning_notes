#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <vector>

using namespace std;

// method 2
// 设区间长度为n;
//(L+L+n-1)*n == 2*M
//  2L = (2*M)/n - n + 1
// n < sqrt(2*M)
long long M;
int main()
{
    cin >> M;
    long long L = 1;
    int i = 0;
    M <<= 1;
    for (int n = 2; n * n <= M; ++n)
    {
        if (M % n == 0 && (M / n - n + 1) % 2 == 0)
        {
            L = (M / n - n + 1) / 2;
            // for (; i < n - 1; ++i)
            //{
            //     cout << L + i << '+';
            // }
            // cout << L + i << endl;
            cout << L << ' ' << L + n - 1 << endl;
        }
    }

    return 0;
}