class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        seen = set()
        x = 1%k
        while x and x not in seen:
            seen.add(x)
            x = (x*10+1)%k
        return -1 if x else len(seen) + 1
