'''
Author: tkzzzzzz6
Date: 2026-04-27 08:12:36
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 08:12:40
'''
# @nc app=nowcoder id=aa48ab4e27b848a8a079b98b2a37f719 topic=314 question=10055930 lang=Python3
# 2026-04-27 08:12:36
# https://www.nowcoder.com/practice/aa48ab4e27b848a8a079b98b2a37f719?tpId=314&tqId=10055930
# [NP42] 公式计算器

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    x,y,z,k = map(int,input().split())

    print((x+y)*(z-k))

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
