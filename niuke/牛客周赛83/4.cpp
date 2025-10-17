#include <iostream>
#include <cmath>

using namespace std;

void solve()
{
    int t;
    cin >> t;
    int n = static_cast<int>(ceil(sqrt(t)));
    n += (n % 2 == 0) ? 1 : 0; // 右上角定位，强制取大于等于t秒的第一个抵达秒数是一个奇数的平方的位置
    int tmp = n * n - t;
    int x, y;
    if (tmp < n)
    { // 上边
        y = n / 2;
        x = (n / 2) - tmp;
    }
    else if (tmp < (2 * n - 1))
    { // 左边
        tmp -= n;
        x = -(n / 2);
        y = (n / 2 - 1) - tmp;
    }
    else if (tmp < (3 * n - 2))
    { // 下边
        tmp -= (2 * n - 1);
        y = -(n / 2);
        x = -(n / 2 - 1) + tmp;
    }
    else
    { // 右边
        tmp -= (3 * n - 2);
        x = n / 2;
        y = -(n / 2 - 1) + tmp;
    }
    cout << x << " " << y << endl;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        solve();
    }
    return 0;
}