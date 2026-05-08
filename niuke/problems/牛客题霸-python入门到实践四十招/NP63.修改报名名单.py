'''
Author: tkzzzzzz6
Date: 2026-04-27 09:32:51
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 09:36:22
'''
# @nc app=nowcoder id=a7f5738b05564534a3daae0d14c890d3 topic=314 question=10059175 lang=Python3
# 2026-04-27 09:32:51
# https://www.nowcoder.com/practice/a7f5738b05564534a3daae0d14c890d3?tpId=314&tqId=10059175
# [NP63] 修改报名名单

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    entry_form = ('Niuniu','Niumei')
    print(entry_form)

    try:
        entry_form[1] = 'Niukele'
    except TypeError:
        print('The entry form cannot be modified!')

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
