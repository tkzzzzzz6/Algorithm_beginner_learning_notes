from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0
        k = 0
        for i in range(1, len(nums)):
            if nums[i] != nums[k]:
                k += 1
                nums[k] = nums[i]
        return k + 1

if __name__ == "__main__":
    solution = Solution()
    nums = [1, 1, 2, 2, 3, 4, 4, 5]
    length = solution.removeDuplicates(nums)
    print(f"Length of array after removing duplicates: {length}")
    print(f"Array after removing duplicates: {nums[:length]}")