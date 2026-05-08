'''
Author: tkzzzzzz6
Date: 2026-04-27 08:53:54
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 08:59:02
'''
# @nc app=nowcoder id=ed009465ad6940609542ef5879a0d697 topic=314 question=10055958 lang=Python3
# 2026-04-27 08:53:54
# https://www.nowcoder.com/practice/ed009465ad6940609542ef5879a0d697?tpId=314&tqId=10055958
# [NP52] 累加数与平均值

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

# def solve():
#     total = 0
#     cnt = 0
#     for age in map(int,input().split()):
#         total += age
#         cnt += 1

#     avg = total / cnt
#     print(total,f"{avg:.1f}")

def solve():
    total = 0
    cnt = 0
    for token in sys.stdin.read().split():
        age = int(token)
        total += age
        cnt += 1

    avg = total / cnt

    print(total,f"{avg:.1f}")

    

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
