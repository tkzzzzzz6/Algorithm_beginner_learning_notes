/*
 * @acwing app=acwing.cn id=70 lang=C++
 *
 * 74. 数组中唯一只出现一次的数字
 */

// @acwing code start

class Solution {
   public:
    int findNumberAppearingOnce(vector<int> &nums) {
        int ones = 0, twos = 0;
        for (auto x : nums) {
            ones = (ones ^ x) & ~twos;
            twos = (twos ^ x) & ~ones;
        }
        return ones;
    }
};
// @acwing code end
