class Solution:
    def concatenatedBinary(self, n: int) -> int:
        MOD = 1_000_000_007
        ans = 0
        for i in range(1,n+1):
            w = i.bit_length()
            ans = (ans << w | i)%MOD
        return ans