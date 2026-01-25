'''
Author: tkzzzzzz6
Date: 2026-01-24 22:58:02
LastEditors: tkzzzzzz6
LastEditTime: 2026-01-24 22:58:07
'''
class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        nums.sort()
        for i in range(n //2):
            ans = max(ans,nums[i]+nums[n-1-i])
        return ans
