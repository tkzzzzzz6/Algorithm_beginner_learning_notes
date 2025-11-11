class Solution:
    def rob(self, nums: List[int]) -> int:
        cache = [0] * (len(nums)+2)
        for i,x in enumerate(nums):
            cache[i+2] = max(cache[i+1],cache[i]+x)
        return cache[-1]