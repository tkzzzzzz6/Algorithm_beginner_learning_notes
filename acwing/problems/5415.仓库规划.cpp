/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-22 07:49:25
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-22 11:30:16
 */
/*
 * @acwing app=acwing.cn id=5418 lang=C++
 *
 * 5415. 仓库规划
 */

// @acwing code start
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1010, M = 10; // N仓库个数上届,M位置编码维数上界
int w[N][M];                // 仓库的位置编码
int n, m;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < m; ++j)
      scanf("%d", &w[i][j]);

  for (int i = 1; i <= n; ++i) {
    int id = 0;
    for (int j = 1; j <= n; ++j) {
      if (i == j)
        continue;
      bool is_bigger = true;
      for (int k = 0; k < m; ++k) {
        if (w[j][k] <= w[i][k]) {
          is_bigger = false;
          break;
        }
      }
      if (is_bigger) // 题目要求输出编号较小的仓库的编号即可
      {
        id = j;
        break;
      }
    }
    printf("%d\n", id);
  }

  return 0;
}

// @acwing code end
