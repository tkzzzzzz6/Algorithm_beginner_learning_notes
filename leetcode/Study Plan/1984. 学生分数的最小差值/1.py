'''
Author: tkzzzzzz6
Date: 2026-01-25 11:03:22
LastEditors: tkzzzzzz6
LastEditTime: 2026-01-25 11:03:26
'''
class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        if k == 1:
            return 0
        nums.sort()
        n = len(nums)
        ans = float('inf')
        for i in range(n-k+1):
            ans = min(ans,nums[i+k-1]-nums[i])
        return ans
