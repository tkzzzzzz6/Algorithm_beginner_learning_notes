'''
Author: tkzzzzzz6
Date: 2026-04-28 07:26:47
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-28 07:26:56
'''
# @nc app=nowcoder id=c42f7bb4618b462dbdc49888cf9b30e4 topic=314 question=10059675 lang=Python3
# 2026-04-28 07:26:47
# https://www.nowcoder.com/practice/c42f7bb4618b462dbdc49888cf9b30e4?tpId=314&tqId=10059675
# [NP80] 数字的十六进制

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    i = int(input())
    print(hex(i))

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
