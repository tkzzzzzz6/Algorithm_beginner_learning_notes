/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-06 14:26:06
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-06 18:46:25
 */
/*
 * @acwing app=acwing.cn id=71 lang=C++
 *
 * 75. 和为S的两个数字
 */

// @acwing code start

class Solution {
   public:
    vector<int> findNumbersWithSum(vector<int> &nums, int target) {
        unordered_set<int> hash;

        for (auto x : nums) {
            if (hash.count(target - x))
                return vector<int>{target - x, x};
            hash.insert(x);
        }

        return vector<int>();
    }
};
// @acwing code end
