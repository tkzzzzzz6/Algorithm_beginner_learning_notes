from typing import List
from functools import cache

class Solution:
    def numberOfPaths(self, grid: List[List[int]], k: int) -> int:
        MOD = 10**9 + 7

        @cache
        def dfs(i: int, j: int, s: int) -> int:
            if i < 0 and j ==0:
                return 1 if s%k ==0 else 0
            if i < 0 or j < 0:
                return 0
            new_s = (s+grid[i][j])%k
            return (dfs(i-1,j,new_s)+dfs(i,j-1,new_s))%MOD

        m, n = len(grid), len(grid[0])
        ans = dfs(m-1, n-1, 0)
        # 清理缓存，防止占用过多内存
        dfs.cache_clear()
        return ans
