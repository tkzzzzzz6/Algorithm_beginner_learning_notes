class Solution:
    def sumAndMultiply(self, n: int) -> int:
        n = str(n)
        ans = ""
        sum = 0
        for c in n:
            if c == '0':
                continue
            else:
                ans += c
                sum += int(c)
        if sum == 0:
            return 0
        return int(ans)*sum