'''
Author: tkzzzzzz6
Date: 2026-01-25 11:03:30
LastEditors: tkzzzzzz6
LastEditTime: 2026-01-25 11:03:33
'''
class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        if k == 1:
            return 0
        nums.sort()
        n = len(nums)
        l,r = 0 ,k-1
        ans = float('inf')
        while r < n:
            ans = min(ans,nums[r]-nums[l])
            l += 1
            r += 1
        return ans
