'''
Author: tkzzzzzz6
Date: 2026-04-28 08:20:15
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-28 08:20:20
'''
# @nc app=nowcoder id=b2ee481ca45c4c57b6ef5dfad1c86197 topic=314 question=10059756 lang=Python3
# 2026-04-28 08:20:15
# https://www.nowcoder.com/practice/b2ee481ca45c4c57b6ef5dfad1c86197?tpId=314&tqId=10059756
# [NP92] 公式计算器

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    print(eval(input()))

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
