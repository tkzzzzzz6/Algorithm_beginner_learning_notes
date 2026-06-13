/*
 * @Author: tkzzzzzz6
 * @Date: 2026-06-03 13:21:58
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-06-03 13:55:21
 */
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

const int maxN = 100005;
int a[maxN] = {0};

string show[5][10] = {
    "XXX", "..X", "XXX", "XXX", "X.X", "XXX", "XXX", "XXX", "XXX", "XXX",
    "X.X", "..X", "..X", "..X", "X.X", "X..", "X..", "..X", "X.X", "X.X",
    "X.X", "..X", "XXX", "XXX", "XXX", "XXX", "XXX", "..X", "XXX", "XXX",
    "X.X", "..X", "X..", "..X", "..X", "..X", "X.X", "..X", "X.X", "..X",
    "XXX", "..X", "XXX", "XXX", "..X", "XXX", "XXX", "..X", "XXX", "XXX"};

inline int read() {
    int ret = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -f;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        ret = ret * 10 + ch - '0';
        ch = getchar();
    }
    return ret * f;
}

int main() {
    int n;
    n = read();
    for (int i = 0; i < n; ++i) {
        char ch = getchar();
        while (ch > '9' || ch < '0') {
            ch = getchar();
        }
        a[i] = ch - '0';
    }

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << show[i][a[j]];
            if (j < n - 1) cout << '.';
        }
        cout << '\n';
    }

    return 0;
}
