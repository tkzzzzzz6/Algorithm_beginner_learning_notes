'''
Author: tkzzzzzz6
Date: 2026-04-27 08:05:32
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 08:07:30
'''
# @nc app=nowcoder id=3456ee52540c4efb8b39e42f0ec4b927 topic=314 question=10055927 lang=Python3
# 2026-04-27 08:05:32
# https://www.nowcoder.com/practice/3456ee52540c4efb8b39e42f0ec4b927?tpId=314&tqId=10055927
# [NP40] 俱乐部的成员

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    club_list = list(input().split())
    s = input()
    print(s in club_list)

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
