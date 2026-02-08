'''
Author: tkzzzzzz6
Date: 2026-02-07 21:23:26
LastEditors: tkzzzzzz6
LastEditTime: 2026-02-07 21:23:31
'''
class Solution:
    def minimumDeletions(self, s: str) -> int:
        ans = delete = s.count('a')

        for c in s:
            delete -= 1 if c == 'a' else -1
            if delete < ans:
                ans = delete
            
        return ans
