/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-28 22:47:07
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-28 22:51:40
 */
#include <iostream>

using namespace std;

int calc_digit_sum(int n) {
    int res = 0;
    while (n > 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    cout << calc_digit_sum(n) << '\n';

    return 0;
}
