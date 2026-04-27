'''
Author: tkzzzzzz6
Date: 2026-04-27 08:51:47
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 08:51:51
'''
# @nc app=nowcoder id=4228edf66a8f4a79808accc55e470520 topic=314 question=10055957 lang=Python3
# 2026-04-27 08:51:47
# https://www.nowcoder.com/practice/4228edf66a8f4a79808accc55e470520?tpId=314&tqId=10055957
# [NP51] 列表的最大与最小

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    nums_list = [x for x in range(10,51)]
    print(nums_list)
    print(f"{nums_list[0]} {nums_list[-1]}")

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
