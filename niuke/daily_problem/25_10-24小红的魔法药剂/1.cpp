// brute solution,有问题
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<int> cost;
vector<pair<int, int>> recipe;

bool is_valid(int mask){
    for (int i = 0; i < n;++i){
        if(!(mask & (1<<i))){
            int x = recipe[i].first-1;
            int y = recipe[i].second-1;

            // 检查配方中的红色药剂是否被购买
            bool has_red_x = mask & (1 << x);
            bool has_red_y = mask & (1 << y);
            if(!has_red_x || !has_red_y)
                return false;
        }
    }
    // 所有药剂都可以获得
    return true;
}

// 计算方案mask的总费用
ll calc_cost(int mask){
    ll total_cost = 0;
    for (int i = 0; i < n;++i){
        if(mask & (1<<i)){
            total_cost += cost[i];
        }
    }
    return total_cost;
}


int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    // 读取信息:红色药剂的价格和蓝色药剂的配方
    cin >> n;

    cost.resize(n);
    for (int i = 0; i < n;++i)
        cin >> cost[i];

    recipe.resize(n);
    for (int i = 0; i < n;++i)
        cin >> recipe[i].first >> recipe[i].second;

    ll min_cost = LLONG_MAX;

    // enumerate all the possible combinations of red potions
    for (int mask = 0; mask < (1 << n);++mask){
        if(!is_valid(mask)){
            continue;
        }

        ll total_cost = calc_cost(mask);

        min_cost = min(min_cost, total_cost);
    }

    cout << min_cost << '\n';

    return 0;
}