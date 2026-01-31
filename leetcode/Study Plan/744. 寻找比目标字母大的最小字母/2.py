'''
Author: tkzzzzzz6
Date: 2026-01-31 19:42:08
LastEditors: tkzzzzzz6
LastEditTime: 2026-01-31 19:42:16
'''
class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        n = len(letters)
        l,r = -1,n
        while l + 1 < r:
            mid = (l+r)//2
            if letters[mid] > target:
                r = mid
            else:
                l = mid

        return letters[r] if r < n else letters[0]
