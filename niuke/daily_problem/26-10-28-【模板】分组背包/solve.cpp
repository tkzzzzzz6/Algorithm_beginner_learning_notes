/*
 * @Author: tkzzzzzz6
 * @Date: 2026-10-28 11:05:03
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-10-28 23:37:40
 */
#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, ll>>> g(101);

    for (int i = 0; i < N; ++i) {
        int w, k;
        ll v;
        cin >> w >> v >> k;
        if (w <= M) g[k].push_back({w, v});
    }

    vector<ll> dp(M + 1, 0);

    for (auto &grp : g) {
        for (int j = M; j >= 1; --j) {
            for (auto &[w, v] : grp) {
                if (w <= j) dp[j] = max(dp[j], dp[j - w] + v);
            }
        }
    }

    cout << dp[M] << '\n';

    return 0;
}
