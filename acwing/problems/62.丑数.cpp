/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-27 19:46:20
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-27 19:55:36
 */
/*
 * @acwing app=acwing.cn id=58 lang=C++
 *
 * 62. 丑数
 */

// @acwing code start

class Solution {
   public:
    int getUglyNumber(int n) {
        vector<int> q = {1};
        if (n == 1)
            return 1;

        int i = 0, j = 0, k = 0;
        while (--n) {
            int t = min(q[i] * 2, min(q[j] * 3, q[k] * 5));
            q.push_back(t);
            if (q[i] * 2 == t)
                i++;
            if (q[j] * 3 == t)
                j++;
            if (q[k] * 5 == t)
                k++;
        }

        return q.back();
    }
};
// @acwing code end
