'''
Author: tkzzzzzz6
Date: 2026-06-02 08:07:51
LastEditors: tkzzzzzz6
LastEditTime: 2026-06-02 08:47:28
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
    def solve(self,start1,duration1,start2,duration2):
        finish1 = math.inf
        for i in range(len(start1)):
            finish1 = min(finish1,start1[i] + duration1[i])
        
        finish2 = math.inf
        for i in range(len(start2)):
            finish2 = min(finish2,max(finish1,start2[i]) + duration2[i])

        return finish2

    def earliestFinishTime(self, landStartTime: List[int], landDuration: List[int], waterStartTime: List[int], waterDuration: List[int]) -> int:
        land2water = self.solve(landStartTime,landDuration,waterStartTime,waterDuration)
        water2land = self.solve(waterStartTime,waterDuration,landStartTime,landDuration)

        return min(land2water,water2land)

# @lc code=end



#
# @lcpr case=start
# [2,8]\n[4,1]\n[6]\n[3]\n
# @lcpr case=end

# @lcpr case=start
# [5]\n[3]\n[1]\n[10]\n
# @lcpr case=end

#
