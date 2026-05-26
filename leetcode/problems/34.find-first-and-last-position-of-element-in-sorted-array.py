#
# @lc app=leetcode.cn id=34 lang=python3
# @lcpr version=30204
#
# [34] 在排序数组中查找元素的第一个和最后一个位置
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
def lower_bound1(nums:List[int],target:int)->int:
    # 闭区间
    l ,r = 0,len(nums)-1
    while l <= r:
        mid = (l + r)//2
        if nums[mid] < target:
            l = mid + 1
        else:
            r = mid - 1

    return l

class Solution:

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        start = lower_bound1(nums,target)
        if start == len(nums) or nums[start] != target:
            return [-1,-1]
        end = lower_bound1(nums,target+1) - 1
        return [start,end]
# @lc code=end



#
# @lcpr case=start
# [5,7,7,8,8,10]\n8\n
# @lcpr case=end

# @lcpr case=start
# [5,7,7,8,8,10]\n6\n
# @lcpr case=end

# @lcpr case=start
# []\n0\n
# @lcpr case=end

#
