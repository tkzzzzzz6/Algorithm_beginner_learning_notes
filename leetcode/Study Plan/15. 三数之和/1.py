class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        # 三元组的顺序不重要
        # let i < j < k
        # 答案中不可以包含重复的三元组
        ans = []
        for i in range(n-2):
            x = nums[i]
            if i > 0 and x == nums[i-1]:
                continue
            # first imporve
            if x + nums[i+1] + nums[i+2] > 0:
                break
            if x + nums[-1] + nums[-2] < 0:
                continue
            j = i + 1
            k = n - 1
            while j < k:
                s = x + nums[j] + nums[k]
                if s < 0:
                    j += 1
                if s > 0:
                    k -= 1
                if s == 0:
                    ans.append([x,nums[j],nums[k]])
                    j += 1
                    while j < k and nums[j] == nums[j-1]:
                        j+=1
                    k -= 1
                    while k>j and nums[k] == nums[k+1]:
                        k-=1
        return ans
                  
                    