/*
 * @Author: tkzzzzzz6
 * @Date: 2026-11-27 09:34:54
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-11-27 09:53:03
 */
#include <cstddef>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> x(n + 2), y(n + 2);
        for (int i = 1; i <= n; ++i) cin >> x[i];
        for (int i = 1; i <= n; ++i) cin >> y[i];
        vector<ll> dp1(n + 2, 0), dp2(n + 2, 0);

        for (int i = n; i >= 1; --i) {
            dp1[i] = max(dp1[i + 1] + x[i] - y[i], dp2[i + 1]);
            dp2[i] = min(dp2[i + 1] + y[i] - x[i], dp1[i + 1]);
        }
        if (dp1[1] > 0)
            cout << "Sunny\n";
        else if (dp1[1] == 0)
            cout << "Draw\n";
        else
            cout << "Aubrey\n";
    }
    return 0;
}
