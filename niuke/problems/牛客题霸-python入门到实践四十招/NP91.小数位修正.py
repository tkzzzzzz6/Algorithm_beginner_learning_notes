'''
Author: tkzzzzzz6
Date: 2026-04-28 08:18:20
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-28 08:18:25
'''
# @nc app=nowcoder id=ee78c92efbcc489699141ec4d0b80ac1 topic=314 question=10059753 lang=Python3
# 2026-04-28 08:18:20
# https://www.nowcoder.com/practice/ee78c92efbcc489699141ec4d0b80ac1?tpId=314&tqId=10059753
# [NP91] 小数位修正

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    f = float(input())

    print(round(f,2))

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
