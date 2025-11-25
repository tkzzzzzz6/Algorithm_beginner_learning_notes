from typing import List
from functools import cache

class Solution:
    def numberOfPaths(self, grid: List[List[int]], k: int) -> int:
        MOD = 10**9 + 7
        m,n = len(grid),len(grid[0])
        f = [[0]*k for _ in range(n+1)]
        f[1][0] = 1
        for row in grid:
            for j,x in enumerate(row):
                new_f = [0]*k
                for s in range(k):
                    new_s = (s+x)%k
                    new_f[s] = (f[j+1][new_s]+f[j][new_s])%MOD
                f[j+1] = new_f
        return f[n][0]
