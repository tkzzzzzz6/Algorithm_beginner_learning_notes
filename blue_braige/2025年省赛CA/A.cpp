#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m;
    int cnt = 0;
    for (int i = 2; cnt < 2025; i++)
    {
        int flag = 0;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            cnt++;
            m = i;
        }
    }
    printf("%d", m);
    return 0;
}