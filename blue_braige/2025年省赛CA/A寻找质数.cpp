#include <iostream>

using namespace std;

long long Lim = 1000000;

int main()
{
    int cnt = 1;

    for (int i = 3; i <= Lim; ++i)
    {
        if (i % 2 == 0)
            continue;
        bool flag = true;
        for (int j = 3; j * j <= i; j += 2)
        {
            if (i % j == 0)
            {
                flag = false;
                break; // 找到因子后可以直接退出
            }
        }

        if (flag)
        {
            cnt++;
            if (cnt == 2025) // 找到第5个质数
            {
                cout << i;
                return 0; // 找到后直接退出程序
            }
        }
    }

    return 0;
}
