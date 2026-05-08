'''
Author: tkzzzzzz6
Date: 2026-04-27 09:37:29
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 09:37:37
'''
# @nc app=nowcoder id=6a62c334fd974905813fb610e93d59bb topic=314 question=10059179 lang=Python3
# 2026-04-27 09:37:29
# https://www.nowcoder.com/practice/6a62c334fd974905813fb610e93d59bb?tpId=314&tqId=10059179
# [NP64] 输出前三同学的成绩

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    name = tuple(input().split())
    print(name[:3])

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
