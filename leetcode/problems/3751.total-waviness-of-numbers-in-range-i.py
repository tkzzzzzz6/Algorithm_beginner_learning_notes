'''
Author: tkzzzzzz6
Date: 2026-06-04 10:23:12
LastEditors: tkzzzzzz6
LastEditTime: 2026-06-04 11:02:17
'''
#
# @lc app=leetcode.cn id=3751 lang=python3
# @lcpr version=30204
#
# [3751] 范围内总波动值 I
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:
        def waviness(num:int)->int:
            s = str(num)
            return sum((a < b > c) or (a > b < c)
                for a,b,c in zip(s,s[1:],s[2:]))
        
        return sum(waviness(n) for n in range(num1,num2+1))
# @lc code=end



#
# @lcpr case=start
# 120\n130\n
# @lcpr case=end

# @lcpr case=start
# 198\n202\n
# @lcpr case=end

# @lcpr case=start
# 4848\n4848\n
# @lcpr case=end

#
