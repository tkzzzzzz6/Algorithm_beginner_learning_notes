'''
Author: tkzzzzzz6
Date: 2026-02-06 21:14:30
LastEditors: tkzzzzzz6
LastEditTime: 2026-02-06 21:15:39
'''
class Solution:
    def minRemoval(self, nums: List[int], k: int) -> int:
        nums.sort()
        max_save = left = 0
        for i,mx in enumerate(nums):
            while nums[left] * k < mx:
                left += 1
            max_save = max(max_save,i-left+1)
        return len(nums) - max_save
