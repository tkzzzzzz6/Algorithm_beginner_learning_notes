/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-30 13:01:06
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-30 13:36:57
 */
/*
 * @acwing app=acwing.cn id=63 lang=C++
 *
 * 67. 数字在排序数组中出现的次数
 */

// @acwing code start

class Solution {
   public:
    int getNumberOfK(vector<int> &nums, int k) {
        if (nums.empty())
            return 0;

        // 第一个 >= k 的位置
        auto pos_left = lower_bound(nums.begin(), nums.end(), k);
        // 第一个 > k 的位置
        auto pos_right = upper_bound(nums.begin(), nums.end(), k);

        return static_cast<int>(pos_right - pos_left);
    }
};
// @acwing code end
