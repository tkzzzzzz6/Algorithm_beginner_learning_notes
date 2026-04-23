'''
Author: tkzzzzzz6
Date: 2026-04-22 22:19:11
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-22 22:19:17
'''
# @nc app=nowcoder id=d3d9737be17d44a7919e3a03e8087270 topic=314 question=10055861 lang=Python3
# 2026-04-22 22:19:11
# https://www.nowcoder.com/practice/d3d9737be17d44a7919e3a03e8087270?tpId=314&tqId=10055861
# [NP20] 增加派对名单（一）

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    names = [x for x in input().split()]
    names.append("Allen")
    print(names)

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
