/*
 * 零钱兑换问题 (Coin Change)
 * 用途：求凑成目标金额需要的最少硬币数、方案数
 * 时间复杂度：O(amount * n)
 * 空间复杂度：O(amount)
 */

#include <bits/stdc++.h>
using namespace std;

// 最少硬币数
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i >= coin) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount] > amount ? -1 : dp[amount];
}

// 组合数（不同顺序算同一种）
int coinChangeWays(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for (int coin : coins) {
        for (int i = coin; i <= amount; i++) {
            dp[i] += dp[i - coin];
        }
    }

    return dp[amount];
}

// 排列数（不同顺序算不同）
int coinChangePermutations(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i >= coin) {
                dp[i] += dp[i - coin];
            }
        }
    }

    return dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << "Minimum coins: " << coinChange(coins, amount) << endl;
    cout << "Number of ways (combinations): " << coinChangeWays(coins, amount) << endl;
    cout << "Number of ways (permutations): " << coinChangePermutations(coins, amount) << endl;

    return 0;
}
