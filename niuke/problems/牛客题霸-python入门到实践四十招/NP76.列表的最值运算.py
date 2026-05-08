'''
Author: tkzzzzzz6
Date: 2026-04-27 22:53:35
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-28 07:19:36
'''
# @nc app=nowcoder id=90c18e8c3a1347ac8a2f40028f959c51 topic=314 question=10059584 lang=Python3
# 2026-04-27 22:53:35
# https://www.nowcoder.com/practice/90c18e8c3a1347ac8a2f40028f959c51?tpId=314&tqId=10059584
# [NP76] 列表的最值运算

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    nums = list(map(int,input().split()))
    # print(type(nums))
    print(max(nums))
    print(min(nums))

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()

# @nc code=end
