#
# @lc app=leetcode.cn id=3121 lang=python3
# @lcpr version=30204
#
# [3121] 统计特殊字母的数量 II
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        ans = 0
        state = [0]*27
        for c in map(ord,word):
            x = c & 31
            if c & 32:
                if state[x] == 0:
                    state[x] = 1
                elif state[x] == 2:
                    state[x] = -1
                    ans -=1
            else:
                if state[x] == 0:
                    state[x] = -1
                elif state[x] == 1:
                    state[x] =2
                    ans+=1
            
        return ans
        
# @lc code=end



#
# @lcpr case=start
# "aaAbcBC"\n
# @lcpr case=end

# @lcpr case=start
# "abc"\n
# @lcpr case=end

# @lcpr case=start
# "AbBCab"\n
# @lcpr case=end

#
