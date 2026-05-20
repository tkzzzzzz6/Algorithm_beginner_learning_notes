/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-14 13:15:30
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-15 14:49:34
 */
/*
 * @acwing app=acwing.cn id=3211 lang=C++
 *
 * 3208. Z字形扫描
 */

// @acwing code start
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 510;
int g[N][N];
int dx[4] = {0, 1, 1, -1}, dy[4] = {1, -1, 0, 1}, dr = 0; //设置偏移量

int main() {
    int n;
    cin >> n;
    // 记录矩阵元素
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%d", &g[i][j]);

    printf("%d ", g[1][1]);
    int x = 1, y = 2;
    for (int i = 1; i <= n * (n * 2); ++i) {
        if (x <= n && y <= n && x >= 1 && y >= 1)
            printf("%d ", g[x][y]);

        int l = x + dx[dr], r = y + dy[dr];
        // 当下一个枚举值是 0,2 类型的偏移或者超出范围的时候,调整枚举方向
        if (dr == 0 || dr == 2 || l > n || l < 1 && r > n || r < 1) {
            dr = (dr + 1) % 4;
            l = x + dx[dr], r = y + dy[dr];
        }

        x = l, y = r;
    }

    return 0;
}

// @acwing code end
