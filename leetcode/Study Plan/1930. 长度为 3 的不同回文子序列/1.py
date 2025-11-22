class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        n = len(s)
        ans = 0
        for i in range(26):
            l,r = 0,n-1
            while l < n and ord(s[l]) - ord('a') != i:
                l += 1
            while r >= 0 and ord(s[r]) - ord('a') != i:
                r -= 1
            if r - l < 2:
                continue
            charset = set()
            for k in range(l+1,r):
                charset.add(s[k])
                ans += len(charset)
        return ans