class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans = left = 0
        window = set()

        for right,c in enumerate(s):
            while c in window:
                window.remove(s[left])
                left += 1

            window.add(c)
            ans = max(ans,right - left + 1)

        return ans
