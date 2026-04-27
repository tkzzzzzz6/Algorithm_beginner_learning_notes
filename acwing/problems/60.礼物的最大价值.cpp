/*
 * @acwing app=acwing.cn id=56 lang=C++
 *
 * 60. 礼物的最大价值
 */

// @acwing code start

class Solution {
public:
  int getMaxValue(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> f(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        f[i][j] = max(f[i - 1][j], f[i][j - 1]) + grid[i - 1][j - 1];
      }
    }

    return f[n][m];
  }
};
// @acwing code end
