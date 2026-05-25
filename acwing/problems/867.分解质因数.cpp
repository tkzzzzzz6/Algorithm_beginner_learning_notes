/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-23 11:35:01
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-23 11:57:53
 */
/*
 * @acwing app=acwing.cn id=869 lang=C++
 *
 * 867. 分解质因数
 */

// @acwing code start
#include <iostream>
using namespace std;

void divide(int x) {
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            int s = 0; // s表示指数
            while (x % i == 0) {
                x /= i;
                s++;
            }
            cout << i << " " << s << endl;
        }
    }

    // 每个数可以用自己表示
    if (x > 1)
        cout << x << " " << 1 << endl;
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        divide(x);
    }
    return 0;
}

// @acwing code end
