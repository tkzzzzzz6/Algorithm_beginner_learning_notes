'''
Author: tkzzzzzz6
Date: 2026-02-02 22:01:02
LastEditors: tkzzzzzz6
LastEditTime: 2026-02-02 22:04:39
'''
from sortedcontainers import SortedList
from typing import List

class Solution:
    def minimumCost(self, nums: List[int], k: int, dist: int) -> int:
        k -= 1
        sum_left = sum(nums[:dist+2])
        L = SortedList(nums[1:dist+2])
        R = SortedList()

        def L2R()->None:
            x = L.pop()
            nonlocal sum_left
            sum_left -= x
            R.add(x)
        
        def R2L()->None:
            x = R.pop(0)
            nonlocal sum_left
            sum_left += x
            L.add(x)

        while len(L)>k:
            L2R()

        ans = sum_left
        for i in range(dist+2,len(nums)):
            # 移除out
            out = nums[i - dist - 1]
            if out in L:
                sum_left -= out
                L.remove(out)
            else:
                R.remove(out)
            # 添加in
            in_val = nums[i]
            if in_val < L[-1]:
                sum_left += in_val
                L.add(in_val)
            else:
                R.add(in_val)
        
            # 维护大小
            if len(L) == k - 1:
                R2L()
            elif len(L) == k + 1:
                L2R()
            
            ans = min(ans,sum_left)

        return ans 
