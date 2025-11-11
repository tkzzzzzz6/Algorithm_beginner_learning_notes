class Solution:
    def rob(self, nums: List[int]) -> int:
        f0 = f1 = 0
        for i,x in enumerate(nums):
            f0, f1 = f1, max(f1, f0 + x)
        return f1