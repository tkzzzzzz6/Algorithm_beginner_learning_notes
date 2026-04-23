'''
Author: tkzzzzzz6
Date: 2026-04-22 22:17:49
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-22 22:18:03
'''
# @nc app=nowcoder id=2b32ef2fd5bb42159e01121fac9fd496 topic=314 question=10055857 lang=Python3
# 2026-04-22 22:17:49
# https://www.nowcoder.com/practice/2b32ef2fd5bb42159e01121fac9fd496?tpId=314&tqId=10055857
# [NP19] 列表的长度

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    names = [ x for x in input().split()]
    print(len(names))

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
