from typing import List
from functools import cache

class Solution:
    def numberOfPaths(self, grid: List[List[int]], k: int) -> int:
        MOD = 10**9 + 7

        @cache
        def dfs(i: int, j: int, s: int) -> int:
            # 如果索引越界，返回0
            if i < 0 or j < 0:
                return 0
            # 当前路径和的前一个状态
            pre_s = (s - grid[i][j]) % k
            # 到达起点，判断路径和是否满足被k整除
            if i == 0 and j == 0:
                return 1 if pre_s == 0 else 0
            # 递归计算上方和左方的状态
            return (dfs(i-1, j, pre_s) + dfs(i, j-1, pre_s)) % MOD

        m, n = len(grid), len(grid[0])
        ans = dfs(m-1, n-1, 0)
        # 清理缓存，防止占用过多内存
        dfs.cache_clear()
        return ans
