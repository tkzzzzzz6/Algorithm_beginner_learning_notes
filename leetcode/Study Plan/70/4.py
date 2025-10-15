class Solution:
    def climbStairs(self, n: int) -> int:
        a, b = 1, 1
        for _ in range(n - 1):
            a, b = b, a + b
        return b

if __name__ == "__main__":
    s = Solution()
    n = 2
    print(s.climbStairs(n))