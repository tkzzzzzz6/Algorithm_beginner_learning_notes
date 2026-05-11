/*
 * @acwing app=acwing.cn id=3201 lang=C++
 *
 * 3198. 窗口
 */

// @acwing code start
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 15;

typedef struct {
    int x1, x2, y1, y2;
    int id;
} Windows;

int main() {
    Windows w[N];
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        w[i] = {x1, x2, y1, y2, i};
    }

    while(m--){
        int x, y;
        cin >> x >> y;
        int res = -1;
        for (int j = n; j >= 1; --j) {
            if (x >= w[j].x1 && x <= w[j].x2 && y >= w[j].y1 && y <= w[j].y2) {
                res = w[j].id;
                auto t = w[j];
                for (int k = j; k < n; ++k)
                    w[k] = w[k + 1];
                w[n] = t;
                break;
            }
        }

        if (res== -1)
            puts("IGNORED");
        else {
            cout << res << endl;
        }
    }

    return 0;
}

// @acwing code end
