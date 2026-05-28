/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-28 18:36:54
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-28 18:44:04
 */
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int y, m, d;
    cin >> y;
    cin >> d;
    m = 1;

    bool isLeap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);

    int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeap) month[2] = 29;
    while (d > month[m]) { // when d == month[m] still in month m
        d -= month[m];
        ++m;
    }

    cout << m << '\n';
    cout << d;

    return 0;
}
