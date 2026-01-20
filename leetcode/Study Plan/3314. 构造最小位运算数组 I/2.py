""" 
x1 = 100100 
100100|100101 = 100101
x2 = 100111
100111|101000 = 101111
可以发现,x|(x+1)的作用是将最右边第一个0转化为1

反之已知x|(x+1) = 101111
x = 100111 or 101011 or 101101 or 101110
要得到最小的 x,就是100111,即末尾连续1对应的最高位
求解的方法是101111取反->010000,取lowbit10000,右移一位1000,和101111异或
最后结果就是1000111
0001000
1001111
但是python中不能直接取反
我们可以这样做
我们要的是1 << (k-1)
y = xxxx01111
y+1 = xxxx10000
t = y ^ (y+1) = 00001111
t + 1 = 1 << (k+1)
bit = (t + 1) >> 2   # = 1 << (k-1)
最后通过异或翻转
x = y ^ bit

"""
from typing import List

class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        ans = list()
        for num in nums:
            if num == 2:
                ans.append(-1)
                continue
            t = num ^ (num+1)
            bit = (t+1)>>2
            ans.append(num^bit)
        return ans
