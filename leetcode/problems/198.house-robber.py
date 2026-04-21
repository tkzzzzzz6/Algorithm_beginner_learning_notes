#
# @lc app=leetcode.cn id=198 lang=python3
# @lcpr version=30204
#
# [198] 打家劫舍
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        f0 ,f1 = 0,0
        for i,x in enumerate(nums):
            fnew = f1
            f0,f1 = fnew,max(f0,f0+x)
        
        return f1

        return f[n+1];
# @lc code=end



#
# @lcpr case=start
# [1,2,3,1]\n
# @lcpr case=end

# @lcpr case=start
# [2,7,9,3,1]\n
# @lcpr case=end

#
