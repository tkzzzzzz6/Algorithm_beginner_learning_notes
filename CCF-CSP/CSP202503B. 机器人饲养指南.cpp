/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-29 14:53:50
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-29 15:28:50
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= min(m, i); ++j) {
            dp[i] = max(dp[i], dp[i - j] + a[j]);
        }
    }

    cout << dp[n];

    return 0;
}
