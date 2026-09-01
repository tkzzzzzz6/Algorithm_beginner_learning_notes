/*
 * @Author: tkzzzzzz6
 * @Date: 2026-08-11 13:58:22
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-08-11 14:01:51
 */
/*
 * @lc app=leetcode.cn id=2996 lang=cpp
 * @lcpr version=30204
 *
 * [2996] 大于等于顺序前缀和的最小缺失整数
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int missingInteger(vector<int> &nums) {
        int sum = nums[0];
        for (int i = 1; i < nums.size() && nums[i] == nums[i - 1] + 1; ++i) {
            sum += nums[i];
        }

        unordered_set<int> s(nums.begin(), nums.end());
        while (s.contains(sum)) {
            sum++;
        }

        return sum;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,2,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,5,1,12,14,13]\n
// @lcpr case=end

 */
