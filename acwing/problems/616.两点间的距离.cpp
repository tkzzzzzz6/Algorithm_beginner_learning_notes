/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-25 12:01:40
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-25 12:08:09
 */
/*
 * @acwing app=acwing.cn id=618 lang=C++
 *
 * 616. 两点间的距离
 */

// @acwing code start
#include <cmath>
#include <iomanip>
#include <iostream>
#include <utility>

using namespace std;

int main() {
    pair<double, double> a, b;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    cout << fixed << setprecision(4)
         << sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second)) << endl;
    return 0;
}

// @acwing code end
