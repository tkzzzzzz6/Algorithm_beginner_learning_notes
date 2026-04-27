'''
Author: tkzzzzzz6
Date: 2026-04-27 07:49:07
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 07:49:11
'''
# @nc app=nowcoder id=13e575e3bd4b4ed0aba7be2fa1efcb3f topic=314 question=10055874 lang=Python3
# 2026-04-27 07:49:07
# https://www.nowcoder.com/practice/13e575e3bd4b4ed0aba7be2fa1efcb3f?tpId=314&tqId=10055874
# [NP32] 牛牛的加减器

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    x = int(input())
    y = int(input())

    print(x+y)
    print(x-y)

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
