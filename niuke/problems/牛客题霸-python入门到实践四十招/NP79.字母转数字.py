'''
Author: tkzzzzzz6
Date: 2026-04-28 07:25:07
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-28 07:25:34
'''
# @nc app=nowcoder id=fc89600d57f74ba7a95f29ba94890634 topic=314 question=10059650 lang=Python3
# 2026-04-28 07:25:07
# https://www.nowcoder.com/practice/fc89600d57f74ba7a95f29ba94890634?tpId=314&tqId=10059650
# [NP79] 字母转数字

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    c = input()
    print(ord(c))

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
