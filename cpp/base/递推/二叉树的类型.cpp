#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <vector>

using namespace std;

int res = 0;

int N;
int main()
{
    cin >> N;
    vector<long long> d(20);
    d[0] = 1;
    d[1] = 1;
    for (int i = 2; i <= N; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            d[i] = d[i] + d[j] * d[i - j - 1];
        }
    }
    cout << d[N] << endl;
    return 0;
}