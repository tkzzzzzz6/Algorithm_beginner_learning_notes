'''
Author: tkzzzzzz6
Date: 2026-04-27 07:57:09
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 07:57:13
'''
# @nc app=nowcoder id=13ca6fc3f6a145a5b6642b26d6575634 topic=314 question=10055878 lang=Python3
# 2026-04-27 07:57:09
# https://www.nowcoder.com/practice/13ca6fc3f6a145a5b6642b26d6575634?tpId=314&tqId=10055878
# [NP36] 谁的数字大

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    ages = list(map(int,input().strip().split()))
    print(True if ages[0] > ages[1] else False)
    print(True if ages[0] < ages[1] else False)

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()

# @nc code=end
