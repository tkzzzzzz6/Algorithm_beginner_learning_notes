/*
 * 背包问题合集 (Knapsack Problems)
 * 包含：01背包、完全背包、多重背包
 * 时间复杂度：O(n * W)
 * 空间复杂度：O(W) (优化后)
 */

#include <bits/stdc++.h>
using namespace std;

// 01背包问题（每个物品最多选一次）
int knapsack01(vector<int>& weights, vector<int>& values, int W) {
    int n = weights.size();
    vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; i++) {
        // 从后向前更新，避免重复使用
        for (int w = W; w >= weights[i]; w--) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }

    return dp[W];
}

// 01背包（返回选择的物品）
pair<int, vector<int>> knapsack01WithItems(vector<int>& weights,
                                           vector<int>& values, int W) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i-1][w];
            if (w >= weights[i-1]) {
                dp[i][w] = max(dp[i][w],
                              dp[i-1][w-weights[i-1]] + values[i-1]);
            }
        }
    }

    // 回溯找出选择的物品
    vector<int> selected;
    int w = W;
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i-1][w]) {
            selected.push_back(i-1);
            w -= weights[i-1];
        }
    }

    reverse(selected.begin(), selected.end());
    return {dp[n][W], selected};
}

// 完全背包（每个物品可以选无限次）
int knapsackUnbounded(vector<int>& weights, vector<int>& values, int W) {
    vector<int> dp(W + 1, 0);

    for (int i = 0; i < weights.size(); i++) {
        // 从前向后更新，允许重复使用
        for (int w = weights[i]; w <= W; w++) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }

    return dp[W];
}

// 多重背包（每个物品有数量限制）
int knapsackBounded(vector<int>& weights, vector<int>& values,
                    vector<int>& counts, int W) {
    vector<int> dp(W + 1, 0);

    // 二进制优化
    vector<int> newWeights, newValues;
    for (int i = 0; i < weights.size(); i++) {
        int count = counts[i];
        for (int k = 1; count > 0; k <<= 1) {
            int c = min(k, count);
            newWeights.push_back(weights[i] * c);
            newValues.push_back(values[i] * c);
            count -= c;
        }
    }

    // 转化为01背包
    for (int i = 0; i < newWeights.size(); i++) {
        for (int w = W; w >= newWeights[i]; w--) {
            dp[w] = max(dp[w], dp[w - newWeights[i]] + newValues[i]);
        }
    }

    return dp[W];
}

// 恰好装满的01背包
int knapsackExact(vector<int>& weights, vector<int>& values, int W) {
    const int NEG_INF = INT_MIN / 2;
    vector<int> dp(W + 1, NEG_INF);
    dp[0] = 0;  // 容量为0时价值为0

    for (int i = 0; i < weights.size(); i++) {
        for (int w = W; w >= weights[i]; w--) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }

    return dp[W] < 0 ? -1 : dp[W];
}

// 二维费用背包（有两个限制条件）
int knapsack2D(vector<int>& weights, vector<int>& volumes,
               vector<int>& values, int maxW, int maxV) {
    vector<vector<int>> dp(maxW + 1, vector<int>(maxV + 1, 0));

    for (int i = 0; i < weights.size(); i++) {
        for (int w = maxW; w >= weights[i]; w--) {
            for (int v = maxV; v >= volumes[i]; v--) {
                dp[w][v] = max(dp[w][v],
                              dp[w-weights[i]][v-volumes[i]] + values[i]);
            }
        }
    }

    return dp[maxW][maxV];
}

// 分组背包（物品分组，每组最多选一个）
int knapsackGrouped(vector<vector<pair<int,int>>>& groups, int W) {
    vector<int> dp(W + 1, 0);

    for (auto& group : groups) {
        for (int w = W; w >= 0; w--) {
            for (auto [weight, value] : group) {
                if (w >= weight) {
                    dp[w] = max(dp[w], dp[w - weight] + value);
                }
            }
        }
    }

    return dp[W];
}

// 使用示例
int main() {
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 6};
    int W = 8;

    // 01背包
    cout << "01 Knapsack: " << knapsack01(weights, values, W) << endl;

    // 带物品追踪
    auto [maxVal, items] = knapsack01WithItems(weights, values, W);
    cout << "Selected items: ";
    for (int idx : items) {
        cout << idx << " ";
    }
    cout << "\nTotal value: " << maxVal << endl;

    // 完全背包
    cout << "\nUnbounded Knapsack: "
         << knapsackUnbounded(weights, values, W) << endl;

    // 多重背包
    vector<int> counts = {1, 2, 1, 1};
    cout << "Bounded Knapsack: "
         << knapsackBounded(weights, values, counts, W) << endl;

    return 0;
}
