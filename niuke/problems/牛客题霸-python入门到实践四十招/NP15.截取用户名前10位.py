'''
Author: tkzzzzzz6
Date: 2026-04-23 08:00:15
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-23 08:00:22
'''
# @nc app=nowcoder id=0d3cd14ca4bc4e67ace6399a041e961e topic=314 question=10055853 lang=Python3
# 2026-04-23 08:00:15
# https://www.nowcoder.com/practice/0d3cd14ca4bc4e67ace6399a041e961e?tpId=314&tqId=10055853
# [NP15] 截取用户名前10位

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    name = input()
    if len(name) > 10:
        name = name[:10]
    print(name)
if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
