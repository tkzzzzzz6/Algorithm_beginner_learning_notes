'''
Author: tkzzzzzz6
Date: 2026-05-26 21:21:16
LastEditors: tkzzzzzz6
LastEditTime: 2026-05-26 21:25:35
'''
#
# @lc app=leetcode.cn id=3120 lang=python3
# @lcpr version=30204
#
# [3120] 统计特殊字母的数量 I
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        upper  = set()
        lower = set()

        for c in word:
            if c == c.lower():
                lower.add(c)
            else:
                upper.add(c.lower())

        return  len(upper & lower)
# @lc code=end
    



#
# @lcpr case=start
# "aaAbcBC"\n
# @lcpr case=end

# @lcpr case=start
# "abc"\n
# @lcpr case=end

# @lcpr case=start
# "abBCab"\n
# @lcpr case=end

#
