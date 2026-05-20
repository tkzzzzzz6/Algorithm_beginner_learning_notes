/*
 * @acwing app=acwing.cn id=76 lang=C++
 *
 * 80. 骰子的点数
 */

// @acwing code start

class Solution {
   public:
    vector<int> numberOfDice(int n) {
        vector<int> res;
        for (int i = n; i <= 6 * n; ++i)
            res.push_back(dfs(n, i));
        return res;
    }

    int dfs(int n, int sum) {
        if (sum < 0)
            return 0;
        if (n == 0)
            return !sum; // 如果 sum = 0返回 1,sum != 0返回 0

        int ans = 0;
        for (int i = 1; i <= 6; ++i) {
            ans += dfs(n - 1, sum - i);
        }

        return ans;
    }
};

// @acwing code end
