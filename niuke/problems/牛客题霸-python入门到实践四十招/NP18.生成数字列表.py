'''
Author: tkzzzzzz6
Date: 2026-04-22 22:13:23
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-22 22:13:37
'''
# @nc app=nowcoder id=2d836a1b27a2401eb338eee62953bd43 topic=314 question=10055856 lang=Python3
# 2026-04-22 22:13:23
# https://www.nowcoder.com/practice/2d836a1b27a2401eb338eee62953bd43?tpId=314&tqId=10055856
# [NP18] 生成数字列表

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    nums = list(map(int,input().split()))
    print(nums)

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
