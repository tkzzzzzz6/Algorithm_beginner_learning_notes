/*
 * @Author: tkzzzzzz6
 * @Date: 2026-06-02 21:55:36
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-06-02 22:21:10
 */
#include <iostream>

using namespace std;

int g[40][40] = {0};

void toNext(int &r, int &c, int n) {
    if (r == 1 && c != n)
        r = n, c += 1;
    else if (c == n && r != 1)
        r -= 1, c = 1;
    else if (r == 1 && c == n)
        r += 1;
    else if (r != 1 && c != n) {
        if (g[r - 1][c + 1] != 0)
            r += 1;
        else
            r -= 1, c += 1;
    }
}

int main() {
    int n;
    cin >> n;

    int r = 1;
    int c = (n / 2) + 1;

    g[r][c] = 1;
    for (int i = 2; i <= n * n; ++i) {
        toNext(r, c, n);
        g[r][c] = i;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << g[i][j];
            if (j < n) cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}
