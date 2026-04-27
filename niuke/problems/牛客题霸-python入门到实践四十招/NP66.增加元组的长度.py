'''
Author: tkzzzzzz6
Date: 2026-04-27 09:43:18
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 09:43:30
'''
# @nc app=nowcoder id=31d26c9dbe454cf9a60c72c72ca958df topic=314 question=10059204 lang=Python3
# 2026-04-27 09:43:18
# https://www.nowcoder.com/practice/31d26c9dbe454cf9a60c72c72ca958df?tpId=314&tqId=10059204
# [NP66] 增加元组的长度

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    my_tuple = tuple(list(range(1,6)))

    print(my_tuple)
    print(len(my_tuple))

    my_tuple += tuple(list(range(6,11)))
    print(my_tuple)
    print(len(my_tuple))



if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()

# @nc code=end
