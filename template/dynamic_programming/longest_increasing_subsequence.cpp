/*
 * 最长递增子序列 (Longest Increasing Subsequence - LIS)
 * 用途：求序列中最长的严格递增子序列
 * 时间复杂度：O(n^2) DP方法，O(n log n) 二分优化
 */

#include <bits/stdc++.h>
using namespace std;

// 方法1：动态规划 O(n^2)
int lisDP(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    vector<int> dp(n, 1);
    int maxLen = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLen = max(maxLen, dp[i]);
    }

    return maxLen;
}

// 方法2：二分优化 O(n log n)
int lisBinarySearch(vector<int>& nums) {
    vector<int> tails;

    for (int num : nums) {
        auto it = lower_bound(tails.begin(), tails.end(), num);
        if (it == tails.end()) {
            tails.push_back(num);
        } else {
            *it = num;
        }
    }

    return tails.size();
}

// 返回LIS序列
vector<int> lisSequence(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> parent(n, -1);
    int maxLen = 1, maxIdx = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            maxIdx = i;
        }
    }

    // 重构序列
    vector<int> lis;
    for (int i = maxIdx; i != -1; i = parent[i]) {
        lis.push_back(nums[i]);
    }
    reverse(lis.begin(), lis.end());

    return lis;
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    cout << "LIS length (DP): " << lisDP(nums) << endl;
    cout << "LIS length (Binary Search): " << lisBinarySearch(nums) << endl;

    auto lis = lisSequence(nums);
    cout << "LIS sequence: ";
    for (int x : lis) cout << x << " ";
    cout << endl;

    return 0;
}
