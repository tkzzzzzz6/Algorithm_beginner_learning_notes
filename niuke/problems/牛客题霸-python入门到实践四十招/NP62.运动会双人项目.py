'''
Author: tkzzzzzz6
Date: 2026-04-27 09:31:09
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 09:31:13
'''
# @nc app=nowcoder id=942c6d28588c481baaba4bc43faf6d65 topic=314 question=10059173 lang=Python3
# 2026-04-27 09:31:09
# https://www.nowcoder.com/practice/942c6d28588c481baaba4bc43faf6d65?tpId=314&tqId=10059173
# [NP62] 运动会双人项目

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    name1 = input().strip()
    name2 = input().strip()

    team = (name1,name2)

    print(team)

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
