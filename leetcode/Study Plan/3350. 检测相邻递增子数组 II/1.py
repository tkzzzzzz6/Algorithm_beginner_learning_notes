class Solution(object):
    def maxIncreasingSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)

        if n < 2:
            return 0

        inc_len = [1]*n

        for i in range(n-2,-1,-1):
            if(nums[i+1] > nums[i]):
                inc_len[i] = inc_len[i+1]+1

        max_k = 0

        for i in range(n-1):
            # 两个递增段是连续的
            max_k = max(inc_len[i]//2,max_k)

            # 两个递增段不是连续的
            j = i + inc_len[i]
            if j < n:
                max_k = max(max_k,min(inc_len[i],inc_len[j]))

        return max_k