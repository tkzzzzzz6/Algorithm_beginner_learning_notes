'''
Author: tkzzzzzz6
Date: 2026-01-22 22:28:44
LastEditors: tkzzzzzz6
LastEditTime: 2026-01-22 22:47:28
'''

class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        cnt = 0

        while len(nums)>1:
            isAscending = True
            minSum = inf
            target_idx = -1

            for i in range(len(nums)-1):
                pair_sum = nums[i]+nums[i+1]
                if nums[i]>nums[i+1]:
                    isAscending = False

                if minSum > pair_sum:
                    minSum = pair_sum
                    target_idx = i
                
            if isAscending:
                break

            cnt += 1
            nums[target_idx] = minSum
            nums.pop(target_idx+1)
        return cnt

        
    
        
