/*
 * @acwing app=acwing.cn id=50 lang=C++
 *
 * 55. 连续子数组的最大和
 */

// @acwing code start

#include <climits>
#include <vector>
class Solution {
   public:
    int maxSubArray(vector<int> &nums) {
        int res = INT_MIN, s = 0;
        for (auto x : nums) {
            if (s < 0)
                s = 0;
            s += x;
            res = max(res, s);
        }
        return res;
    }
};
// @acwing code end
