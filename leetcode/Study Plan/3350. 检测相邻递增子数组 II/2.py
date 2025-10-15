class Solution(object):
    def maxIncreasingSubarrays(self, nums:list[int])->int:
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)

        pre,current,ans = 1,0,0

        for i in range(n):
            if nums[i] > nums[i-1]:
                current +=1
            else:
                pre,current = current,1
            ans = max(ans,min(pre,current))
            ans = max(ans,current//2)

        return ans