#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int n;  // 药剂种类数量
    cin >> n;

    // 存储每种红色药剂的购买价格
    vector<int> red_cost(n);
    for (int i = 0; i < n; ++i) {
        cin >> red_cost[i];
    }

    ll total_cost = 0;  // 最小总花费

    // 对每种药剂，计算获得它的最小成本
    for (int i = 0; i < n; ++i) {
        // 读取合成配方
        pair<int, int> recipe; // 合成第 i 种蓝色药剂需要的两种红色药剂编号
        cin >> recipe.first >> recipe.second;

        // 计算两种获得方式的成本
        int cost_buy_red = red_cost[i]; // 直接购买红色
        int cost_make_blue = red_cost[recipe.first - 1] + red_cost[recipe.second - 1];  // 合成蓝色

        // 选择成本较低的方案
        total_cost += min(cost_buy_red, cost_make_blue);
    }

    //输出
    cout << total_cost << '\n';

    return 0;
}