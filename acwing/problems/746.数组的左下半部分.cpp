/*
 * @Author: tkzzzzzz6
 * @Date: 2026-08-16 19:40:23
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-08-16 19:40:32
 */
/*
 * @acwing app=acwing.cn id=748 lang=C++
 *
 * 746. 数组的左下半部分
 */

// @acwing code start
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    char c;
    cin >> c;
    double sum = 0, x = 0;
    int col = 0;
    for (int i = 0; i < 12; ++i) {
        int j = 0;
        while (j < col) {
            cin >> x;
            sum += x;
            ++j;
        }
        while (j < 12) {
            cin >> x;
            ++j;
        }
        ++col;
    }

    if (c == 'S') {
        cout << sum << endl;
    } else {
        cout << fixed << setprecision(1) << sum / 66.0 << endl;
    }
    return 0;
}

// @acwing code end
