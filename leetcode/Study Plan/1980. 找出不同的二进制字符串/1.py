'''
Author: tkzzzzzz6
Date: 2026-03-08 23:32:29
LastEditors: tkzzzzzz6
LastEditTime: 2026-03-08 23:32:33
'''
class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        st = {int(s,2) for s in nums}

        ans = 0
        while ans in st:
            ans += 1

        n = len(nums)

        return f"{ans:0{n}b}"
