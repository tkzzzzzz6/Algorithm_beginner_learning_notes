/*
 * @Author: tkzzzzzz6
 * @Date: 2026-08-16 20:09:51
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-08-16 20:18:46
 */
/*
 * @acwing app=acwing.cn id=751 lang=C++
 *
 * 749. 数组的上方区域
 */

// @acwing code start
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    char c;
    cin >> c;
    double sum = 0, x = 0;
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            cin >> x;
            if (i < j && j < 11 - i) {
                sum += x;
            }
        }
    }

    cout << fixed << setprecision(1);
    if (c == 'S') {
        cout << sum << endl;
    } else {
        cout << sum / 30.0 << endl;
    }
    return 0;
}

// @acwing code end
