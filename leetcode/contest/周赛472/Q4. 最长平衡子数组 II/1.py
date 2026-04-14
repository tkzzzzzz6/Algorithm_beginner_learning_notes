class Solution:
    def longestBalanced(self, nums: List[int]) -> int:
        n = len(nums)

        # ܵĳȿʼö
        for length in range(n, 0, -1):
            # öгΪlength
            for i in range(n - length + 1):
                even_set = set()
                odd_set = set()

                # ͳ[i, i+length-1]
                for j in range(i, i + length):
                    if nums[j] % 2 == 0:
                        even_set.add(nums[j])
                    else:
                        odd_set.add(nums[j])

                # ҵƽ飬
                if len(even_set) == len(odd_set):
                    return length


