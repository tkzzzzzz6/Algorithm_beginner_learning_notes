'''
Author: tkzzzzzz6
Date: 2026-04-28 08:21:26
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-28 08:21:38
'''
# @nc app=nowcoder id=398ceccfafeb4de88640e76128634902 topic=314 question=10059764 lang=Python3
# 2026-04-28 08:21:26
# https://www.nowcoder.com/practice/398ceccfafeb4de88640e76128634902?tpId=314&tqId=10059764
# [NP93] 创建集合

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    s = set(input().split())
    print(sorted(s))

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
