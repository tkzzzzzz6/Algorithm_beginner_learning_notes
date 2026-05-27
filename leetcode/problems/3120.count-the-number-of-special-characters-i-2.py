'''
Author: tkzzzzzz6
Date: 2026-05-26 21:21:16
LastEditors: tkzzzzzz6
LastEditTime: 2026-05-26 21:37:07
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
        mask = [0]*2
        for c in map(ord,word):
            mask[c >>  5 & 1] |= 1<<(c & 31)

        return bin(mask[0] & mask[1]).count("1")
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
