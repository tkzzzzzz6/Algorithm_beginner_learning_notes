'''
Author: tkzzzzzz6
Date: 2026-03-08 23:32:02
LastEditors: tkzzzzzz6
LastEditTime: 2026-03-08 23:32:08
'''
class Solution:
    def minFlips(self, s: str) -> int:
        ans = n = len(s)
        cnt = 0
        for i in range(n*2 - 1):
            if ord(s[i%n]) % 2 != i %2:
                cnt += 1
            left = i - n + 1
            if left < 0:
                continue
            ans = min(ans,cnt,n-cnt)
            if ord(s[left]) % 2 != left % 2:
                cnt -= 1
        return ans
