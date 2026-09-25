/*
 * @Author: tkzzzzzz6
 * @Date: 2026-08-16 20:02:31
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-08-16 20:04:17
 */
/*
 * @acwing app=acwing.cn id=750 lang=C++
 *
 * 748. 数组的右下半部分
 */

// @acwing code start
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    char c;
    cin >> c;
    double sum = 0, x = 0;
    int col = 12;
    for (int i = 0; i < 12; ++i) {
        int j = 0;
        while (j < col) {
            cin >> x;
            ++j;
        }
        while (j < 12) {
            cin >> x;
            sum += x;
            ++j;
        }
        --col;
    }

    cout << fixed << setprecision(1);
    if (c == 'S') {
        cout << sum << endl;
    } else {
        cout << sum / 66.0 << endl;
    }
    return 0;
}

// @acwing code end
