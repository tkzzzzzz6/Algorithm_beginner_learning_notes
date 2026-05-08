'''
Author: tkzzzzzz6
Date: 2026-04-27 22:50:02
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 22:50:21
'''
# @nc app=nowcoder id=74f7e7f2344f4754bc56d862838cbfc3 topic=314 question=10059563 lang=Python3
# 2026-04-27 22:50:02
# https://www.nowcoder.com/practice/74f7e7f2344f4754bc56d862838cbfc3?tpId=314&tqId=10059563
# [NP75] 使用字典计数

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    str = input()
    count_dict = {}

    for c in str:
        count_dict[c] = count_dict.get(c,0) + 1

    print(count_dict)


if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()

# @nc code=end
