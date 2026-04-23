'''
Author: tkzzzzzz6
Date: 2026-04-23 07:53:36
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-23 07:53:49
'''
# @nc app=nowcoder id=3bd78a6de34a447fa49571a03f164fd3 topic=314 question=2365106 lang=Python3
# 2026-04-23 07:53:36
# https://www.nowcoder.com/practice/3bd78a6de34a447fa49571a03f164fd3?tpId=314&tqId=2365106
# [NP12] 格式化输出（二）

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    name = input()

    print(name.lower())
    print(name.upper())
    # print(name.capitalize())
    print(name.title())
if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
