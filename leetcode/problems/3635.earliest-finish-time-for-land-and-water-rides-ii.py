'''
Author: tkzzzzzz6
Date: 2026-06-03 09:03:54
LastEditors: tkzzzzzz6
LastEditTime: 2026-06-03 09:13:15
'''
#
# @lc app=leetcode.cn id=3635 lang=python3
# @lcpr version=30204
#
# [3635] 最早完成陆地和水上游乐设施的时间 II
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def earliestFinishTime(self, landStartTime: List[int], landDuration: List[int], waterStartTime: List[int], waterDuration: List[int]) -> int:
        def solve(s1:List[int],d1:List[int],s2:List[int],d2:List[int])->int:
            finish1 = inf
            for i in range(len(s1)):
                finish1 = min(finish1,s1[i] + d1[i])

            finish2 = inf
            for i in range(len(s2)):
                finish2 = min(finish2,max(finish1,s2[i]) + d2[i])
            
            return finish2

        land2water = solve(landStartTime,landDuration,waterStartTime,waterDuration);
        water2land = solve(waterStartTime,waterDuration,landStartTime,landDuration)

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
