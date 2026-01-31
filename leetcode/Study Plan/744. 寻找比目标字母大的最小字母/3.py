'''
Author: tkzzzzzz6
Date: 2026-01-31 19:44:17
LastEditors: tkzzzzzz6
LastEditTime: 2026-01-31 19:44:25
'''
class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        i = bisect_right(letters,target)
        return letters[i] if i < len(letters) else letters[0]
