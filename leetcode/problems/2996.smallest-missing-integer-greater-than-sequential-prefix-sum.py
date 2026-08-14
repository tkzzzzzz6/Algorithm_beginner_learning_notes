'''
Author: tkzzzzzz6
Date: 2026-08-11 13:57:44
LastEditors: tkzzzzzz6
LastEditTime: 2026-08-11 14:09:43
'''
#
# @lc app=leetcode.cn id=2996 lang=python3
# @lcpr version=30204
#
# [2996] 大于等于顺序前缀和的最小缺失整数
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
from typing import List
from itertools import *

class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        s = nums[0]

        for x,y in pairwise(nums):
            if y != x + 1:
                break
            s += y

        st = set(nums)
        while s in st:
            s += 1

        return s


# @lc code=end



#
# @lcpr case=start
# [1,2,3,2,5]\n
# @lcpr case=end

# @lcpr case=start
# [3,4,5,1,12,14,13]\n
# @lcpr case=end

#
