'''
Author: tkzzzzzz6
Date: 2026-05-29 16:24:02
LastEditors: tkzzzzzz6
LastEditTime: 2026-05-29 16:26:56
'''
#
# @lc app=leetcode.cn id=3300 lang=python3
# @lcpr version=30204
#
# [3300] 替换为数位和以后的最小元素
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def minElement(self, nums: List[int]) -> int:
        res = inf
        for x in nums:
            s = 0
            while x > 0:
                s += x % 10
                x //= 10
            res = min(s,res)

        return res
# @lc code=end



#
# @lcpr case=start
# [10,12,13,14]\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3,4]\n
# @lcpr case=end

# @lcpr case=start
# [999,19,199]\n
# @lcpr case=end

#
