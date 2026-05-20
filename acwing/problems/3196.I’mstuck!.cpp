/*
 * @acwing app=acwing.cn id=3199 lang=C++
 *
 * 3196. I’m stuck!
 */

// @acwing code start
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 55;
char g[N][N];
bool st1[N][N], st2[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int n, m;

bool check(int x, int y, int k) {
    char c = g[x][y];
    if (c == '+' || c == 'T' || c == 'S')
        return true;
    if (c == '|' && k % 2 == 0)
        return true;
    if (c == '-' && k % 2 == 1)
        return true;
    if (c == '.' && k == 2)
        return true;
    return false;
}

// 从初始位置 S 可以移动到此方格
void dfs1(int x, int y) {
    st1[x][y] = true;

    for (int i = 0; i < 4; ++i) {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= n || b < 0 || b >= m || g[a][b] == '#')
            continue;
        if (st1[a][b])
            continue;
        if (check(x, y, i))
            dfs1(a, b);
    }
}

// 从目标位置 T 不可以移动到的位置->反推
void dfs2(int x, int y) {
    st2[x][y] = true;

    for (int i = 0; i < 4; ++i) {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= n || b < 0 || b >= m || g[a][b] == '#')
            continue;
        if (st2[a][b])
            continue;
        if (check(a, b, i ^ 2))
            dfs2(a, b);
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        cin >> g[i];

    int tx, ty;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == 'S')
                dfs1(i, j);
            else if (g[i][j] == 'T') {
                tx = i, ty = j;
                dfs2(i, j);
            }
        }
    }

    if (!st1[tx][ty])
        puts("I'm stuck!");
    else {
        int res = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (st1[i][j] && !st2[i][j])
                    res++;

        cout << res << endl;
    }

    return 0;
}

// @acwing code end
