#include <iostream>
using namespace std;

int main()
{
    int m = 20, n = 20, num = 0;
    int cnt = m + n - 1; // 确定斜对角线层级

    // 累加前cnt-1层的数字
    for (int i = 1; i < cnt; i++)
    {
        num += i;
    }

    // 判断斜对角线方向
    if (cnt % 2 == 0)
    { // 偶数层：右上→左下方向
        int row = 1;
        while (row <= m)
        {
            num++;
            row++;
        }
    }
    else
    { // 奇数层：左下→右上方向
        int row = cnt;
        while (row >= m)
        {
            num++;
            row--;
        }
    }

    cout << num << endl;
    return 0;
}