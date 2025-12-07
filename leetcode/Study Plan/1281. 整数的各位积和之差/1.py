class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        prod, s = 1,0
        while n > 0:
            prod *= n % 10
            s += n % 10

            n //= 10

        return prod - s
