#
# @lc app=leetcode.cn id=2574 lang=python3
# @lcpr version=30204
#
# [2574] 左右元素和的差值
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start

# total = leftsum + nums[i] + rightsum
# |rightsum - leftsum| = |total - 2*leftsum - nums[i]|

class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        res = []
        total = sum(nums)
        leftsum = 0
        for i in range(len(nums)):
            res.append(abs(total - 2*leftsum - nums[i]))
            leftsum += nums[i]

        return res
# @lc code=end



#
# @lcpr case=start
# [10,4,8,3]\n
# @lcpr case=end

# @lcpr case=start
# [1]\n
# @lcpr case=end

#
