#
# @lc app=leetcode.cn id=1291 lang=python3
# @lcpr version=30204
#
# [1291] 顺次数
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        ans = []

        for len in range(2,10):
            for start in range(1,11-len):
                num = 0
                for digit in range(start,start+len):
                    num = 10*num + digit

                if num >= low and num <= high:
                    ans.append(num)

        return ans

# @lc code=end
