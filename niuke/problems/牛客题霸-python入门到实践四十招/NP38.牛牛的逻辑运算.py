'''
Author: tkzzzzzz6
Date: 2026-04-27 08:02:10
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 08:03:15
'''
# @nc app=nowcoder id=d1f6b7dd048f48c58d974553f0c5a3bc topic=314 question=10055925 lang=Python3
# 2026-04-27 08:02:10
# https://www.nowcoder.com/practice/d1f6b7dd048f48c58d974553f0c5a3bc?tpId=314&tqId=10055925
# [NP38] 牛牛的逻辑运算

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    x,y = map(int,input().split())
    print(x and y)
    print(x or y)
    print(not x)
    print(not y)

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
