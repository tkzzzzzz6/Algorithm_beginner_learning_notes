/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-07 11:23:20
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-07 13:33:13
 */
/*
 * @acwing app=acwing.cn id=78 lang=C++
 *
 * 82. 圆圈中最后剩下的数字
 */

// @acwing code start
#include <list>
class Solution {
   public:
    int lastRemaining(int n, int m) {
        queue<int> q;
        for (int i = 0; i < n; ++i)
            q.push(i);
        int k = 0;
        while (q.size() > 1) {
            if (k == m - 1) {
                q.pop();
                k = 0;
            }
            ++k;
            q.push(q.front());
            q.pop();
        }

        return q.front();
    }
};
// @acwing code end
