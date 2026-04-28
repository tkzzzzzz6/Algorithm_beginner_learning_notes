'''
Author: tkzzzzzz6
Date: 2026-04-28 07:24:22
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-28 07:24:30
'''
# @nc app=nowcoder id=ae9a8d7ec8de4379b2430519804e7712 topic=314 question=10059648 lang=Python3
# 2026-04-28 07:24:22
# https://www.nowcoder.com/practice/ae9a8d7ec8de4379b2430519804e7712?tpId=314&tqId=10059648
# [NP78] 正数输出器

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    x = int(input())
    print(abs(x))

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
