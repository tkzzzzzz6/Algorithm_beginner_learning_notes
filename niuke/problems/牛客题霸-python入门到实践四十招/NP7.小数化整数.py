'''
Author: tkzzzzzz6
Date: 2026-04-22 22:02:53
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-23 07:48:25
'''
# @nc app=nowcoder id=e302a62c1fbd4bbf84793e8c52ce4705 topic=314 question=10055829 lang=Python3
# 2026-04-22 22:02:53
# https://www.nowcoder.com/practice/e302a62c1fbd4bbf84793e8c52ce4705?tpId=314&tqId=10055829
# [NP7] 小数化整数

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    x = float(input())
    print(int(x))

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
