/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-23 17:12:12
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-23 17:23:04
 */
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int res = 0;
    while (n--) {
        int ones = 0, digits = 0;
        int a;
        cin >> a;
        while (a > 0) {
            if (a & 1) ones++;
            digits++;
            a >>= 1;
        }
        if (ones == digits - ones) {
            res++;
        }
    }
    cout << res;
    return 0;
}
