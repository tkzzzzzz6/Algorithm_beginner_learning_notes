#
# @lc app=leetcode.cn id=2452 lang=python3
# @lcpr version=30204
#
# [2452] 距离字典两次编辑以内的单词
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
        ans = []
        for q in queries:
            for s in dictionary:
                if sum(x != y for x,y in zip(q,s)) <= 2:
                    ans.append(q)
                    break

        return ans

# @lc code=end



#
# @lcpr case=start
# ["word","note","ants","wood"]\n["wood","joke","moat"]\n
# @lcpr case=end

# @lcpr case=start
# ["yes"]\n["not"]\n
# @lcpr case=end

#
