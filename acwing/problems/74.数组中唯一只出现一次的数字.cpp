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
            // 上面两行代码等效于下面的代码
            // int o1 = ones;
            // ones = (ones ^ x) & ~twos;
            // twos = (~o1 & ~x & twos) | (o1 & x & ~twos);
        }
        return ones;
    }
};
// @acwing code end
