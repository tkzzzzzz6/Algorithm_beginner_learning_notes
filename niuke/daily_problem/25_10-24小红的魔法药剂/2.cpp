#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int n;  // ҩ
    cin >> n;

    // 洢ÿֺɫҩĹ۸
    vector<int> red_cost(n);
    for (int i = 0; i < n; ++i) {
        cin >> red_cost[i];
    }

    ll total_cost = 0;  // Сܻ

    // ÿҩСɱ
    for (int i = 0; i < n; ++i) {
        // ȡϳ䷽
        pair<int, int> recipe; // ϳɵ i ɫҩҪֺɫҩ
        cin >> recipe.first >> recipe.second;

        // ֻ÷ʽĳɱ
        int cost_buy_red = red_cost[i]; // ֱӹɫ
        int cost_make_blue = red_cost[recipe.first - 1] + red_cost[recipe.second - 1];  // ϳɫ

        // ѡɱϵ͵ķ
        total_cost += min(cost_buy_red, cost_make_blue);
    }

    //
    cout << total_cost << '\n';

    return 0;
}
