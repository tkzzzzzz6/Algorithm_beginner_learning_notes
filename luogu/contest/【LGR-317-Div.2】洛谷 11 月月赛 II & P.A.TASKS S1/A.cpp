/*
 * @Author: tkzzzzzz6
 * @Date: 2026-11-21 17:03:26
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-11-21 17:04:09
 */
#include <iostream>

using namespace std;

int main() {
    int w, x, y;
    cin >> w >> x >> y;
    cout << (w * w + x * w + y * w - 1) + (1 + 3 * (w - 1)) << '\n';
    return 0;
}
