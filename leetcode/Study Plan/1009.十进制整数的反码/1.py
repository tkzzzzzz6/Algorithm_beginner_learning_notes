'''
Author: tkzzzzzz6
Date: 2026-03-11 23:50:30
LastEditors: tkzzzzzz6
LastEditTime: 2026-03-11 23:51:36
'''
class Solution:
    def bitwiseComplement(self, n: int) -> int:
        if n == 0:
            return 1
        w = n.bit_length()

        return ((1 << w) -1) ^ n
