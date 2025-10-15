#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

// int a[110][110];

int main() {
    int i, j, tot, x, y, n;
    cin >> n;
    int a[n+2][n+2];
    memset(a, 0, sizeof(a));
    x = 0;
    y = 0;
    a[x][y] = 1;
    tot = 1;

    while (tot < n * n) { // 顺时针填写数字
        while (y + 1 < n && !a[x][y + 1]) a[x][++y] = ++tot; // 上方一行从左到右
        while (x + 1 < n && !a[x + 1][y]) a[++x][y] = ++tot;  // 右方一列从上到下
        while (y - 1 >= 0 && !a[x][y - 1]) a[x][--y] = ++tot; // 下方一行从右到左
        while (x - 1 >= 0 && !a[x - 1][y]) a[--x][y] = ++tot; // 左方一列从下到上
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%3d", a[i][j]);
        cout << endl;
    }
    
    cout << endl;
    return 0;
}