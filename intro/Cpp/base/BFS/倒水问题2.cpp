#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
// #include <stdio.h>
#include <string>
#include <cstring>
using namespace std;

int t, d[360][5], bz[4][8][11], full[4] = {0, 3, 7, 10};
int i, j;

int main()
{
    scanf_s("%d", &t);
    memset(d, 0, sizeof(d));
    memset(bz, 0, sizeof(bz));
    d[1][1] = 0;
    d[1][2] = 0;
    d[1][3] = 10;
    d[1][4] = 0;
    bz[0][0][10] = 1;
    i = 0, j = 1;
    while (i < j)
    {
        ++i;
        int current_steps = d[i][4];
        for (int p = 1; p < 4; ++p)
        {
            for (int q = 1; q < 4; ++q)
            {
                if (p != q && d[i][p] > 0 && d[i][q] < full[q])
                {
                    ++j;
                    for (int k = 1; k < 4; ++k)
                        d[j][k] = d[i][k];
                    d[j][4] = current_steps;
                    if (d[j][p] + d[j][q] <= full[q])
                    {
                        d[j][q] += d[j][p];
                        d[j][p] = 0;
                    }
                    else
                    {
                        int pour = full[q] - d[j][q];
                        d[j][p] -= pour;
                        d[j][q] = full[q];
                    }
                    d[j][4] = current_steps + 1;
                    if (d[j][3] == t)
                    {
                        printf("%d", d[j][4]);
                        return 0;
                    }
                    if (bz[d[j][1]][d[j][2]][d[j][3]] == 0)
                    {
                        bz[d[j][1]][d[j][2]][d[j][3]] = 1;
                    }
                    else
                        --j;
                }
            }
        }
    }
    printf("%d", -1);
    return 0;
}
