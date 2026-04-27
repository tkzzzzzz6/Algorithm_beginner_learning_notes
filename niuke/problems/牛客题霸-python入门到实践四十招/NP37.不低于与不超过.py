'''
Author: tkzzzzzz6
Date: 2026-04-27 07:58:30
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 08:00:43
'''
# @nc app=nowcoder id=0be51146e30f4fa0ad1a6aac9078c1af topic=314 question=10055884 lang=Python3
# 2026-04-27 07:58:30
# https://www.nowcoder.com/practice/0be51146e30f4fa0ad1a6aac9078c1af?tpId=314&tqId=10055884
# [NP37] 不低于与不超过

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    k,x,y = map(float,input().split())

    print(True if k <= x else False)
    print(True if k >= y else False)

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
