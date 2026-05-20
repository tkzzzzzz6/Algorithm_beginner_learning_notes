/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-30 16:11:07
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-30 16:13:54
 */
/*
 * @acwing app=acwing.cn id=64 lang=C++
 *
 * 68. 0到n-1中缺失的数字
 */

// @acwing code start

class Solution {
   public:
    int getMissingNumber(vector<int> &nums) {
        int res = nums.size() * (nums.size() + 1) / 2;
        for (auto x : nums)
            res -= x;
        return res;
    }
};
// @acwing code end
