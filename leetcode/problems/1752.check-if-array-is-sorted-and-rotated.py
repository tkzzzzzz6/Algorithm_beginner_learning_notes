#
# @lc app=leetcode.cn id=1752 lang=python3
# @lcpr version=30204
#
# [1752] 检查数组是否经排序和轮转得到
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def check(self, nums: List[int]) -> bool:
        is_sorted = nums[0] >= nums[-1]
        
        n = len(nums)
        for i in range(1,n):
            if nums[i-1] > nums[i]:
                if not is_sorted:
                    return False
                is_sorted = False
        
        return True


# @lc code=end



#
# @lcpr case=start
# [3,4,5,1,2]\n
# @lcpr case=end

# @lcpr case=start
# [2,1,3,4]\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3]\n
# @lcpr case=end

#
