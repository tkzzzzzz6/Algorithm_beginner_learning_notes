class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        
        s = set(nums)

        for i in range(1,len(nums)+2):
            if i*k not in s:
                return i*k
