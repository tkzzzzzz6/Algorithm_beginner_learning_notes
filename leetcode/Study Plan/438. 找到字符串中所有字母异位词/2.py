'''
Author: tkzzzzzz6
Date: 2026-03-12 00:57:22
LastEditors: tkzzzzzz6
LastEditTime: 2026-03-12 00:57:24
'''
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        cnt = Counter(p)
        ans = []

        left = 0
        for right,c in enumerate(s):
            cnt[c] -= 1
            while cnt[c] < 0:
                cnt[s[left]] += 1
                left += 1
            if right - left + 1 == len(p):
                ans.append(left)

        return ans
