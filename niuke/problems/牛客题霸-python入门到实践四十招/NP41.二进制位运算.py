'''
Author: tkzzzzzz6
Date: 2026-04-27 08:08:58
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 08:09:02
'''
# @nc app=nowcoder id=fa89690611f84cdcaba9a843e884310b topic=314 question=10055929 lang=Python3
# 2026-04-27 08:08:58
# https://www.nowcoder.com/practice/fa89690611f84cdcaba9a843e884310b?tpId=314&tqId=10055929
# [NP41] 二进制位运算

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    x,y = map(int,input().split())

    print(x&y)
    print(x|y)

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
