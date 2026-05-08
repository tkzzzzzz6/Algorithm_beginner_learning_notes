'''
Author: tkzzzzzz6
Date: 2026-04-28 08:11:00
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-28 08:11:16
'''
# @nc app=nowcoder id=381fd07d1d4a4152adb6969c080d40b9 topic=314 question=10059950 lang=Python3
# 2026-04-28 08:11:00
# https://www.nowcoder.com/practice/381fd07d1d4a4152adb6969c080d40b9?tpId=314&tqId=10059950
# [NP88] 句子拆分

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    print(input().split())

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
