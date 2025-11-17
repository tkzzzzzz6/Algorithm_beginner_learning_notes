#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define min(a, b) (a < b ? a : b)
int ans, n, a[12][2], d[12][12], p[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
inline void calc()
{                         // 计算路径长
    int tmp = d[0][p[1]]; // 从初始位置开始
    for (int i = 1; i < n; i++)
    {
        tmp += d[p[i]][p[i + 1]];
        if (tmp > ans)
            return;
    }
    ans = min(ans, tmp + d[p[n]][0]); // 最终回到初始位置
}
int main()
{
    int T, x, y;
    scanf("%d", &T);
    while (T--)
    {
        ans = 0x3f3f3f3f;
        scanf("%d%d%d%d%d", &x, &y, &a[0][0], &a[0][1], &n); // a[0]是初始位置
        for (int i = 1; i <= n; i++)
            scanf("%d %d", &a[i][0], &a[i][1]), p[i] = i;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                d[i][j] = abs(a[i][0] - a[j][0]) + abs(a[i][1] - a[j][1]);
        do
        {
            calc();
        } while (next_permutation(p + 1, p + n + 1)); // 枚举1~n的全排列
        printf("The shortest path has length %d\n", ans);
    }
}