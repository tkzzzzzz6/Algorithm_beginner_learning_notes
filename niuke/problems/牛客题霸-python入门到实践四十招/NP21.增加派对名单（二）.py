'''
Author: tkzzzzzz6
Date: 2026-04-22 22:20:12
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-22 22:21:14
'''
# @nc app=nowcoder id=cc57f3f2ea274489b1ead14a9ddcee64 topic=314 question=10055862 lang=Python3
# 2026-04-22 22:20:12
# https://www.nowcoder.com/practice/cc57f3f2ea274489b1ead14a9ddcee64?tpId=314&tqId=10055862
# [NP21] 增加派对名单（二）

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    names = input().split()
    names.insert(0,"Allen")
    print(names)

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
