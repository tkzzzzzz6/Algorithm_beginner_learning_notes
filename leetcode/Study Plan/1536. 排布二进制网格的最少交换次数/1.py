'''
Author: tkzzzzzz6
Date: 2026-03-02 09:53:03
LastEditors: tkzzzzzz6
LastEditTime: 2026-03-02 09:54:37
'''
class Solution:
    def minSwaps(self, grid: List[List[int]]) -> int:
        n = len(grid)
        tail_zeros = [n]*n
        for i in range(n):
            for j in range(n-1,-1,-1):
                if grid[i][j]:
                    tail_zeros[i] = n - 1 - j
                    break

        ans = 0
        for i in range(n-1):
            need_zeros = n - 1 - i
            for j in range(i,n):
                if tail_zeros[j] >= need_zeros:
                    ans += j - i
                    tail_zeros[i+1:j+1] = tail_zeros[i:j]
                    break
            else:
                return -1
        return ans
