'''
Author: tkzzzzzz6
Date: 2026-05-25 15:08:44
LastEditors: tkzzzzzz6
LastEditTime: 2026-05-25 15:09:42
'''
#
# @lc app=leetcode.cn id=33 lang=python3
# @lcpr version=30204
#
# [33] 搜索旋转排序数组
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if not nums:
            return -1
        
        l,r = 0,len(nums) - 1   

        while l <= r:
            mid = (l+r)//2
            if nums[mid] == target:
                return mid
            
            if nums[0] <= nums[mid]:
                if nums[0] <= target < nums[mid]:
                    r = mid -1
                else:
                    l = mid + 1
            else:
                if nums[mid] < target <= nums[-1]:
                    l = mid + 1
                else:
                    r = mid - 1

        return -1
# @lc code=end



#
# @lcpr case=start
# [4,5,6,7,0,1,2]\n0\n
# @lcpr case=end

# @lcpr case=start
# [4,5,6,7,0,1,2]\n3\n
# @lcpr case=end

# @lcpr case=start
# [1]\n0\n
# @lcpr case=end

#
