'''
Author: tkzzzzzz6
Date: 2026-06-16 11:33:24
LastEditors: tkzzzzzz6
LastEditTime: 2026-06-16 11:36:04
'''
#
# @lc app=leetcode.cn id=3612 lang=python3
# @lcpr version=30204
#
# [3612] 用特殊操作处理字符串 I
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def processStr(self, s: str) -> str:
        ans = []
        for c in s:
            if c == '*':
                if ans:
                    ans.pop()
            elif c == '#':
                ans += ans
            elif c == '%':
                ans.reverse()
            else:
                ans += c
        
        return "".join(ans)

# @lc code=end



#
# @lcpr case=start
# "a#b%*"\n
# @lcpr case=end

# @lcpr case=start
# "z*#"\n
# @lcpr case=end

#
