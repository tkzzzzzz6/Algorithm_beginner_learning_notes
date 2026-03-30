'''
Author: tkzzzzzz6
Date: 2026-03-12 00:42:45
LastEditors: tkzzzzzz6
LastEditTime: 2026-03-12 00:42:52
'''
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans = left = 0
        cnt = defaultdict(int)

        for right,c in enmerate(s):
            cnt[c] += 1
            while cnt[c] > 1:
                cnt[s[left]] -= 1
                left += 1
            ans = max(ans,right - left + 1)
        return ans
