#include <iostream>
using namespace std;

const int MAXN = 505;
int n;
int a[MAXN][MAXN];

bool check()
{
    // 检查每个位置是否可以通过操作变成0
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // 如果是正数，必须能减到0
            if (a[i][j] > 0)
            {
                // 检查是否存在一个相邻位置的数大于等于当前位置
                if (a[i - 1][j] >= a[i][j] || a[i + 1][j] >= a[i][j] ||
                    a[i][j - 1] >= a[i][j] || a[i][j + 1] >= a[i][j])
                {
                    return false;
                }
            }
            // 如果是负数，必须能加到0
            else if (a[i][j] < 0)
            {
                // 检查是否存在一个相邻位置的数小于等于当前位置
                if (a[i - 1][j] <= a[i][j] || a[i + 1][j] <= a[i][j] ||
                    a[i][j - 1] <= a[i][j] || a[i][j + 1] <= a[i][j])
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    cin >> n;

    // 初始化边界为0
    for (int i = 0; i <= n + 1; i++)
    {
        a[0][i] = a[n + 1][i] = a[i][0] = a[i][n + 1] = 0;
    }

    // 读入数据
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << (check() ? "YES" : "NO") << endl;
    return 0;
}