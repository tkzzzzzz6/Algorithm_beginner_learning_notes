/*
 * @acwing app=acwing.cn id=69 lang=C++
 *
 * 73. 数组中只出现一次的两个数字
 */

// @acwing code start

class Solution {
   public:
    vector<int> findNumsAppearOnce(vector<int> &nums) {
        int sum = 0; // sum 最后的结果是 x^y
        for (auto x : nums)
            sum ^= x;
        int k = 0;
        while (!(sum >> k & 1))
            ++k;

        int first = 0;
        for (auto x : nums) {
            if (x >> k & 1)
                first ^= x;
        }

        return vector<int>{first, sum ^ first}; // 第二个不同的数直接用 sum 和 first 异或,不需要再遍历
    }
};
// @acwing code end
