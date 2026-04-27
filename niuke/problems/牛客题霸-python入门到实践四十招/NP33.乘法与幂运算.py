'''
Author: tkzzzzzz6
Date: 2026-04-27 07:49:51
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 07:49:56
'''
# @nc app=nowcoder id=2b0e586dfdbe4da4aabccbc94a4f7224 topic=314 question=10055875 lang=Python3
# 2026-04-27 07:49:51
# https://www.nowcoder.com/practice/2b0e586dfdbe4da4aabccbc94a4f7224?tpId=314&tqId=10055875
# [NP33] 乘法与幂运算

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    x = int(input())
    y = int(input())

    print(x*y)
    print(x**y)

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
