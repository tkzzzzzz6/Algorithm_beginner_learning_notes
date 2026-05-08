'''
Author: tkzzzzzz6
Date: 2026-04-28 08:36:25
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-28 08:39:42
'''
# @nc app=nowcoder id=7a5e2f1ed2594e38bad804323a775c93 topic=314 question=10059954 lang=Python3
# 2026-04-28 08:36:25
# https://www.nowcoder.com/practice/7a5e2f1ed2594e38bad804323a775c93?tpId=314&tqId=10059954
# [NP96] 球的表面积

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def get_surface(r:float):
    return 4*math.pi*r*r

def solve():
    radius = [1, 2, 4, 9, 10, 13]

    for r in radius:
        print(round(get_surface(r),2))



if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
