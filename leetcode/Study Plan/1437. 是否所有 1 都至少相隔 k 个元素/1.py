class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        last1 = -inf

        for index,num in enumerate(nums):
            if num != 1:
                continue
            if index - last1 - 1 < k:
                return False
            last1 = index

        return True
