'''
Author: tkzzzzzz6
Date: 2026-04-27 09:15:04
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 09:15:08
'''
# @nc app=nowcoder id=4713c1513cfa43b5a3dd0013059880fe topic=314 question=10059167 lang=Python3
# 2026-04-27 09:15:04
# https://www.nowcoder.com/practice/4713c1513cfa43b5a3dd0013059880fe?tpId=314&tqId=10059167
# [NP60] 跳过列表的某个元素

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    for x in range(1,16):
        if x == 13:
            continue
        elif x == 15:
            print(x,end='')
        else:
            print(x,end=' ')

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
