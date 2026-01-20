""" 
x1 = 100100 
100100|100101 = 100101
x2 = 100111
100111|101000 = 101111
可以发现,x|(x+1)的作用是将最右边第一个0转化为1

反之已知x|(x+1) = 101111
x = 100111 or 101011 or 101101 or 101110
要得到最小的 x,就是100111,即末尾连续1对应的最高位
y = x | (x + 1) 的结果一定以连续的 1 结尾,因为质数中只有2是偶数
为得到最小的 x，只需找到 y 末尾连续 1 的个数 k，
然后把这串 1 中最高位（第 k-1 位）的 1 清掉：
x = y - (1 << (k - 1))
"""
from typing import List

class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        ans = list()
        for num in nums:
            if num == 2:
                ans.append(-1)
                continue
            k = 0
            while num & (1<<k):
                k+=1
            ans.append(num-(1<<(k-1)))
        return ans
