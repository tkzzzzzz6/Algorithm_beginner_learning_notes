#include <cmath>
#include <iostream>
using namespace std;

// 直接使用等比数列求和公式进行计算
int main()
{
    double s, n;
    cin >> s;
    n = ceil(log(1 - 0.01 * s) / log(0.98));
    cout << n;
    return 0;
}