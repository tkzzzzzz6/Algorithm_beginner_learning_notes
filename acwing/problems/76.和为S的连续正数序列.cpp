/*
 * @acwing app=acwing.cn id=72 lang=C++
 *
 * 76. 和为S的连续正数序列
 */

// @acwing code start

//因为这里的数为正整数,且 i 和 j 的移动满足单调性,所以可以采用双指针的方法

class Solution {
   public:
    vector<vector<int>> findContinuousSequence(int sum) {
        vector<vector<int>> res;
        for (int i = 1, j = 1, s = 1; i < sum; ++i) {
            while (s < sum)
                s += ++j;
            if (s == sum && j - i + 1 > 1) {
                vector<int> line;
                for (int k = i; k <= j; ++k)
                    line.push_back(k);
                res.push_back(line);
            }
            s -= i;
        }

        return res;
    }
};
// @acwing code end
