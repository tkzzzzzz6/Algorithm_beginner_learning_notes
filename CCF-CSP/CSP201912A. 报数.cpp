/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-26 14:29:14
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-26 14:48:52
 */
#include <iostream>

using namespace std;

bool has_seven(int x) {
    while (x > 0) {
        if (x % 10 == 7) return true;
        x /= 10;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int cnt = 0;
    int d[4] = {0};
    int current = 1;
    int turn = 0;
    while (cnt < n) {
        if (current % 7 == 0 || has_seven(current)) {
            d[turn]++;
        } else {
            cnt++; // 有效报出一个数
        }
        turn = (turn + 1) % 4;
        current++;
    }

    for (int i = 0; i < 4; ++i)
        cout << d[i] << "\n";

    return 0;
}
