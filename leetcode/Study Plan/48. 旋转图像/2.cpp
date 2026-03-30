/*
 * @Author: tkzzzzzz6
 * @Date: 2026-03-22 18:32:49
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-03-23 14:06:15
 */
class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size(), m = matrix[0].size();
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        swap(matrix[i][j], matrix[j][i]);
        // swap(matrix[i][j],matrix[i][m - j - 1]);
      }
      ranges::reverse(matrix[i]);
    }
  }
};
