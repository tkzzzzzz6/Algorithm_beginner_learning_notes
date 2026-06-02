'''
Author: tkzzzzzz6
Date: 2026-06-01 14:20:03
LastEditors: tkzzzzzz6
LastEditTime: 2026-06-01 14:33:31
'''
#
# @lc app=leetcode.cn id=2144 lang=python3
# @lcpr version=30204
#
# [2144] 打折购买糖果的最小开销
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        cost.sort(reverse = True)
        return sum(cost) - sum(cost[2::3])
# @lc code=end



#
# @lcpr case=start
# [1,2,3]\n
# @lcpr case=end

# @lcpr case=start
# [6,5,7,9,2,2]\n
# @lcpr case=end

# @lcpr case=start
# [5,5]\n
# @lcpr case=end

#
