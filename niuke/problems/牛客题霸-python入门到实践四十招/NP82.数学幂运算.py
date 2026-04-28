'''
Author: tkzzzzzz6
Date: 2026-04-28 07:28:03
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-28 07:29:12
'''
# @nc app=nowcoder id=eeb02352695342caaa4d1df269c34f30 topic=314 question=10059690 lang=Python3
# 2026-04-28 07:28:03
# https://www.nowcoder.com/practice/eeb02352695342caaa4d1df269c34f30?tpId=314&tqId=10059690
# [NP82] 数学幂运算

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    x,y = [int(x) for x in input().split()]
    print(pow(x,y))
    print(pow(y,x))

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
