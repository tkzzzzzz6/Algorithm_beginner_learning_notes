'''
Author: tkzzzzzz6
Date: 2026-01-31 19:31:46
LastEditors: tkzzzzzz6
LastEditTime: 2026-01-31 19:31:52
'''
class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        l, r = 0, len(letters)
        while l < r:
            mid = (l + r) // 2
            if letters[mid] <= target:
                l = mid + 1
            else:
                r = mid
        return letters[l % len(letters)]
