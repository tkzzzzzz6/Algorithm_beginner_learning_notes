
# 周一到周日之和是 7*(1+2+..+k) + (1+2+3+4+5+6)*k = 7*k*(k+1)//2+21*k

# 假如k周余下s天。那么需要再加上 k*s+s*(s+1)//2

class Solution:
    def totalMoney(self, n: int) -> int:
        k,s = divmod(n,7)
        return 7*k*(k+1)//2 + 21*k + k*s + s*(s+1)//2
