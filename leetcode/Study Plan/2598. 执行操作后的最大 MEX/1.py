class Solution:
    def findSmallestInteger(self, nums: List[int], value: int) -> int:

        # frequency count of non-neggative remainders for each number
        mp = Counter(x % value for x in nums)

        # greedy search to find MEX
        mex = 0
        while mp[mex % value] > 0:
            mp[mex % value] -= 1
            mex +=1
        return mex
