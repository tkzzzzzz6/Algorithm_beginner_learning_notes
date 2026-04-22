#include <vector>
#include <climits>
class Solution {
public:
  vector<vector<int>> minAbsDiff(vector<vector<int>> &grid, int k) {
    int m = grid.size(), n = grid[0].size();
    vector ans(m - k + 1, vector<int>(n - k + 1));

    for (int i = 0; i < m - k + 1; ++i) {
      for (int j = 0; j < n - k + 1; ++j) {
        vector<int> a;
        for (int x = 0; x < k; ++x) {
          for (int y = 0; y < k; ++y) {
            a.push_back(grid[i + x][j + y]);
          }
        }

        ranges::sort(a);

        int res = INT_MAX;
        for (int p = 1; p < a.size(); ++p) {
          if (a[p] - a[p - 1] > 0) { // 这里排序了,题目要求任意两个数不相同
            res = min(res, a[p] - a[p - 1]);
          }
        }
        if (res != INT_MAX)
          ans[i][j] = res;
      }
    }
    return ans;
  }
};
