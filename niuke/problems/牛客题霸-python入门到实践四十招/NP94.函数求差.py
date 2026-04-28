'''
Author: tkzzzzzz6
Date: 2026-04-28 08:22:16
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-28 08:22:21
'''
# @nc app=nowcoder id=ad1a6e344add40bdb05c44ce086c1e94 topic=314 question=2549719 lang=Python3
# 2026-04-28 08:22:16
# https://www.nowcoder.com/practice/ad1a6e344add40bdb05c44ce086c1e94?tpId=314&tqId=2549719
# [NP94] 函数求差

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def cal(a,b):
    return a-b

def solve():
    x = int(input())
    y = int(input())
    print(cal(x,y))
    print(cal(y,x))

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
