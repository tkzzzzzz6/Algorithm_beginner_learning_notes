'''
Author: tkzzzzzz6
Date: 2026-04-27 08:16:20
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 08:16:25
'''
# @nc app=nowcoder id=83602ea86f1e4e6ca42d5ebffff34ca8 topic=314 question=2368138 lang=Python3
# 2026-04-27 08:16:20
# https://www.nowcoder.com/practice/83602ea86f1e4e6ca42d5ebffff34ca8?tpId=314&tqId=2368138
# [NP44] 判断列表是否为空

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    my_list = []
    if my_list:
        print('my_list is not empty!')
    else:
        print('my_list is empty!')

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
