/*
 * @Author: tkzzzzzz6
 * @Date: 2026-03-02 09:01:57
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-03-02 09:02:03
 */
#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long ans = 0;
    while (n > 0) {
        ans += n & 1;
        n >>= 1;
    }
    cout << ans << endl;
}
