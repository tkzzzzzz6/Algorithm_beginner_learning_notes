'''
Author: tkzzzzzz6
Date: 2026-04-28 07:27:25
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-28 07:27:34
'''
# @nc app=nowcoder id=3ee66b6b76314a9ab7ff22d97f999ac1 topic=314 question=10059687 lang=Python3
# 2026-04-28 07:27:25
# https://www.nowcoder.com/practice/3ee66b6b76314a9ab7ff22d97f999ac1?tpId=314&tqId=10059687
# [NP81] 数字的二进制表示

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    i = int(input())
    print(bin(i))

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
