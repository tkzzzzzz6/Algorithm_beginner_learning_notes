// 原地二维前缀和
#include <vector>

using namespace std;

class Solution {
public:
  int countSubmatrices(vector<vector<int>> &grid, int k) {
    int m = grid.size(), n = grid[0].size();
    int ans = 0;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if(i > 0)grid[i][j] += grid[i-1][j];
        if(j > 0)grid[i][j] += grid[i][j-1];
        if(i >0 && j > 0) grid[i][j] -= grid[i-1][j-1];

        if(grid[i][j] >k) break;
        ++ans;
      }
    }
    return ans;
  }
};
