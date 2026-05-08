'''
Author: tkzzzzzz6
Date: 2026-04-27 09:05:05
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 09:05:15
'''
# @nc app=nowcoder id=d86587eaa6dd47109933c732e69bb3d2 topic=314 question=2367305 lang=Python3
# 2026-04-27 09:05:05
# https://www.nowcoder.com/practice/d86587eaa6dd47109933c732e69bb3d2?tpId=314&tqId=2367305
# [NP55] 2的次方数

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    my_list = []

    for i in range(1,11):
        my_list.append(2**i)

    for x in my_list:
        print(x)
    

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
