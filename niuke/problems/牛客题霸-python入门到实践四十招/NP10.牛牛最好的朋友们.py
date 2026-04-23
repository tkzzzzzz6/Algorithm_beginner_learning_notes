'''
Author: tkzzzzzz6
Date: 2026-04-23 07:51:35
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-23 07:51:42
'''
# @nc app=nowcoder id=ff823846af304a9a8cbbdfe2c9e8874c topic=314 question=10055850 lang=Python3
# 2026-04-23 07:51:35
# https://www.nowcoder.com/practice/ff823846af304a9a8cbbdfe2c9e8874c?tpId=314&tqId=10055850
# [NP10] 牛牛最好的朋友们

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    name1 = input()
    name2 = input()
    print(name1 + name2)

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
