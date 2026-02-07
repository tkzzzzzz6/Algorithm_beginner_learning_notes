/*
 * @Author: tkzzzzzz6
 * @Date: 2026-02-07 12:16:06
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-02-07 13:16:25
 */

//  滑动窗口(循环数组实现) + 贪心
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
#define endl '\n'
int main() {
    int n, m;
    ll x;
    cin >> n >> m >> x;
    vector<ll> window(m, 0);

    ll current_sum = 0;
    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        ll val;
        cin >> val;

        int idx = i % m;
        current_sum -= window[idx];

        window[idx] = val;
        current_sum += val;

        if (current_sum > x) {
            ll diff = current_sum - x;
            ans += diff;

            current_sum -= diff;
            window[idx] -= diff;
        }
    }

    cout << ans << endl;
}
