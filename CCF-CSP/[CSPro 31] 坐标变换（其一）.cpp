/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-26 22:00:56
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-26 22:05:24
 */
#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int dx = 0, dy = 0;
    while (n--) {
        int x, y;
        cin >> x >> y;
        dx += x, dy += y;
    }

    while (m--) {
        int x, y;
        cin >> x >> y;
        cout << x + dx << ' ' << y + dy << '\n';
    }
    return 0;
}
