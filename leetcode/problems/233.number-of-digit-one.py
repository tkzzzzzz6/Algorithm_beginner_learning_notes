'''
Author: tkzzzzzz6
Date: 2026-06-05 11:40:20
LastEditors: tkzzzzzz6
LastEditTime: 2026-06-05 11:43:39
'''
#
# @lc app=leetcode.cn id=233 lang=python3
# @lcpr version=30204
#
# [233] 数字 1 的个数
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def countDigitOne(self, n: int) -> int:
        s = list(map(int,str(n)))

        @cache
        def dfs(i:int,cnt:int,isLimit:bool)->int:
            if i == len(s):
                return cnt
            
            up = s[i] if isLimit else 9
            res = 0
            for d in range(up+1):
                res += dfs(i+1,cnt + (d == 1),isLimit and (d == up))

            return res
        
        return dfs(0,0,True)
# @lc code=end



#
# @lcpr case=start
# 13\n
# @lcpr case=end

# @lcpr case=start
# 0\n
# @lcpr case=end

#
