'''
Author: tkzzzzzz6
Date: 2026-04-28 07:29:40
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-28 07:29:50
'''
# @nc app=nowcoder id=01da65ec58f84fba93611aae4735f68b topic=314 question=10059694 lang=Python3
# 2026-04-28 07:29:40
# https://www.nowcoder.com/practice/01da65ec58f84fba93611aae4735f68b?tpId=314&tqId=10059694
# [NP83] 错误出现的次数

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    print(input().split().count('0'))

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
