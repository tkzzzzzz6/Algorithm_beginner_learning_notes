/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-29 11:14:47
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-29 11:37:00
 */

// 需要判断移动过程中是否超出场地，50%的数据不考虑是否出界，可以读入指令的时候，对指令进行消除，比如f消除b,r消除l
// 如果移动的目标位置不在场地范围内，则机器人位置保持不变
#include <iostream>
#include <string>

using namespace std;

void moveTo(int &x, int &y, char c, int n) {
    int tx = x, ty = y;
    switch (c) {
    case 'f': ty += 1; break;
    case 'b': ty -= 1; break;
    case 'r': tx += 1; break;
    case 'l': tx -= 1; break;
    default: break;
    }

    if (tx < 1 || ty < 1 || tx > n || ty > n) return;

    x = tx, y = ty;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < k; ++i) {
        int x, y;
        string instructs;
        cin >> x >> y >> instructs;
        bool flag = true;
        int j = 0;
        while (flag && j < (int)instructs.size()) {
            moveTo(x, y, instructs[j], n);
            ++j;
        }

        if (flag) {
            cout << x << ' ' << y << '\n';
        }
    }

    return 0;
}
