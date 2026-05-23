/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-23 11:24:43
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-23 16:52:33
 */
/*
 * @acwing app=acwing.cn id=868 lang=C++
 *
 * 866. 试除法判定质数
 */

// @acwing code start
#include <iostream>
using namespace std;

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= x / i; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        cout << ((is_prime(x)) ? "Yes" : "No") << endl;
    }
    return 0;
}
// @acwing code end
