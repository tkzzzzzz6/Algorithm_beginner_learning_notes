class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        pre = 2
        while n:
            cur = n % 2
            if cur == pre:
                return False
            pre = cur
            n //= 2
        return True
