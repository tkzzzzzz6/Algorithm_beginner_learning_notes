class Solution:
    def minOperations(self, s: str) -> int:
        ans = 0
        for i,x in enumerate(s):
            if int(x) == i % 2:
                ans += 1

        return min(ans,len(s) - ans)
