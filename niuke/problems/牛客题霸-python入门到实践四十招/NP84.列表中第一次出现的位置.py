'''
Author: tkzzzzzz6
Date: 2026-04-28 07:31:29
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-28 07:31:37
'''
# @nc app=nowcoder id=9326aae320dc4ccba545fcee194aef8a topic=314 question=10059714 lang=Python3
# 2026-04-28 07:31:29
# https://www.nowcoder.com/practice/9326aae320dc4ccba545fcee194aef8a?tpId=314&tqId=10059714
# [NP84] 列表中第一次出现的位置

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    names_list = input().split()
    print(names_list.index('NiuNiu'))

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
