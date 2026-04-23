'''
Author: tkzzzzzz6
Date: 2026-04-22 22:10:46
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-22 22:12:45
'''
# @nc app=nowcoder id=349954d559e1494ba5f83e42388ba8ea topic=314 question=10055854 lang=Python3
# 2026-04-22 22:10:46
# https://www.nowcoder.com/practice/349954d559e1494ba5f83e42388ba8ea?tpId=314&tqId=10055854
# [NP17] 生成列表

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    line = input()
    names = list(line.split())
    print(names)


if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
