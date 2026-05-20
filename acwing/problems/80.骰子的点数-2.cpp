/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-06 22:02:08
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-07 10:54:52
 */
/*
 * @acwing app=acwing.cn id=76 lang=C++
 *
 * 80. 骰子的点数
 */

// @acwing code start

class Solution {
   public:
    vector<int> numberOfDice(int n) {
        vector<vector<int>> f(n + 1, vector<int>(6 * n + 1));
        f[0][0] = 1;

        for (int i = 1; i <= n; ++i) {                 // 枚举投掷次数
            for (int j = 1; j <= 6 * i; ++j) {         // 枚举点数总和
                for (int k = 1; k <= min(j, 6); ++k) { // 枚举最后一次投掷
                    f[i][j] += f[i - 1][j - k];
                }
            }
        }

        vector<int> res;
        for (int i = n; i <= 6 * n; ++i)
            res.push_back(f[n][i]);
        return res;
    }
};

// @acwing code end
