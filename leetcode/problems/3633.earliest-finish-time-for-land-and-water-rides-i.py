'''
Author: tkzzzzzz6
Date: 2026-06-02 08:07:51
LastEditors: tkzzzzzz6
LastEditTime: 2026-06-02 08:33:03
'''
#
# @lc app=leetcode.cn id=3633 lang=python3
# @lcpr version=30204
#
# [3633] 最早完成陆地和水上游乐设施的时间 I
#



# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
from typing import List
import math

class Solution:
    def earliestFinishTime(self, landStartTime: List[int], landDuration: List[int], waterStartTime: List[int], waterDuration: List[int]) -> int:
        n = len(landStartTime)
        m = len(waterStartTime)
        res = math.inf

        for i in range(n):
            for j in range(m):
                land = landStartTime[i] + landDuration[i]
                land2water = max(land, waterStartTime[j]) + waterDuration[j]
                res = min(res, land2water)

                water = waterStartTime[j] + waterDuration[j]
                water2land = max(water, landStartTime[i]) + landDuration[i]
                res = min(res, water2land)

        return res

# @lc code=end



#
# @lcpr case=start
# [2,8]\n[4,1]\n[6]\n[3]\n
# @lcpr case=end

# @lcpr case=start
# [5]\n[3]\n[1]\n[10]\n
# @lcpr case=end

#
