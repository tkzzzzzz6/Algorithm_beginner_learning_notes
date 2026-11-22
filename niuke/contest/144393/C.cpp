/*
 * @Author: tkzzzzzz6
 * @Date: 2026-11-22 10:34:15
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-11-22 10:52:24
 */
// Nowcoder Compiler: C++（clang++18）
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    vector<int> first(n + 1, 0);
    vector<ll> dp(2 * n + 1, 0);

    for (int i = 1; i <= 2 * n; ++i) {
        int x;
        cin >> x;

        dp[i] = dp[i - 1] + 1;

        if (first[x] == 0) {
            first[x] = i;
        } else {
            int l = first[x];
            ll len = i - l + 1;
            dp[i] = max(dp[i], dp[l - 1] + len * len);
        }
    }

    cout << dp[2 * n] << '\n';

    return 0;
}
