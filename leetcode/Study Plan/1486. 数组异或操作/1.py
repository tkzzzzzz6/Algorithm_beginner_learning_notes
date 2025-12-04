class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        ans = start
        for i in range(n):
            start += 2
            ans ^= start
        return ans
            
