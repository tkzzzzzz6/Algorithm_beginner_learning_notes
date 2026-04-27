/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-27 19:46:20
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-27 20:02:02
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

        int i = 1, j = 1, k = 1;
        while (--n) {
            int t = min(i * 2, min(j * 3, k * 5));
            q.push_back(t);
            if (i * 2 == t)
                i = t;
            if (j * 3 == t)
                j = t;
            if (k * 5 == t)
                k = t;
        }

        return q.back();
    }
};
// @acwing code end
