class Solution:
    def prefixesDivBy5(self, nums: List[int]) -> List[bool]:
        ans = [False] * len(nums)
        x = 0
        for i,bit in enumerate(nums):
            x = (x << 1 | bit) % 5
            ans[i] = x == 0
        return ans
