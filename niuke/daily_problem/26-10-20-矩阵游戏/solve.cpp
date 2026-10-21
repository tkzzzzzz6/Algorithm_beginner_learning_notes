/*
 * @Author: tkzzzzzz6
 * @Date: 2026-10-20 12:31:07
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-10-20 21:26:46
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin >> n;
    long long ans = n;
    for (long long i = 2; i * i <= n; ) {
        if (n % i == 0) {
            n /= i;        // 除以当前最小质因子
            ans += n;
        } else {
            i++;
        }
    }
    if (n > 1) ans += 1;   // 剩下的 n 是质数，最后一步 n -> 1
    cout << ans << endl;
}
