// 二维前缀和
#include <vector>

using namespace std;

class Solution {
public:
  int numberOfSubmatrices(vector<vector<char>> &grid) {
    int m = grid.size(), n = grid[0].size();
    int ans = 0;
    vector<vector<int>> sum_x(m + 1, vector<int>(n + 1));
    vector<vector<int>> sum_y(m + 1, vector<int>(n + 1));

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        sum_x[i + 1][j + 1] = sum_x[i][j + 1] + sum_x[i + 1][j] - sum_x[i][j];
        sum_y[i + 1][j + 1] = sum_y[i][j + 1] + sum_y[i + 1][j] - sum_y[i][j];
        if (grid[i][j] == 'X') {
            sum_x[i+1][j+1] += 1;
        }else if(grid[i][j] == 'Y'){
            sum_y[i + 1][j + 1] += 1;
        }

        if (sum_x[i + 1][j + 1] > 0 && sum_x [i + 1][j + 1] == sum_y[i + 1][j + 1])
          ans += 1;
      }
    }
    return ans;
  }
};
