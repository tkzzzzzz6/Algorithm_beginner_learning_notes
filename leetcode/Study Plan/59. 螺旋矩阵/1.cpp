/*
#include <vector>
 * @Author: tkzzzzzz6
 * @Date: 2026-04-05 18:50:13
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-05 18:50:16
 */
class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0));
    int start_x = 0, start_y = 0;
    int cnt = 1;
    int loop = n / 2;
    int offset = 1;
    int i, j;
    int mid = n / 2;
    while (loop--) {
      i = start_x;
      j = start_y;
      for (; j < n - offset; ++j)
        res[i][j] = cnt++;
      for (; i < n - offset; ++i)
        res[i][j] = cnt++;
      for (; j > start_y; --j)
        res[i][j] = cnt++;
      for (; i > start_x; --i)
        res[i][j] = cnt++;
      ++offset;
      ++start_x;
      ++start_y;
    }
    if ((n & 1) == 1) { // 矩阵的宽度是奇数的话,单独填充最中间的元素
      res[mid][mid] = cnt;
    }
    return res;
  }
};
