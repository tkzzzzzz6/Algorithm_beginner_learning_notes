'''
Author: tkzzzzzz6
Date: 2026-04-27 08:59:53
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 09:00:58
'''
# @nc app=nowcoder id=b369718b3a904c2f845d135781120048 topic=314 question=2367288 lang=Python3
# 2026-04-27 08:59:53
# https://www.nowcoder.com/practice/b369718b3a904c2f845d135781120048?tpId=314&tqId=2367288
# [NP53] 前10个偶数

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    my_list = [x for x in range(0,20,2)]
    for x in my_list:
        print(x)

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
