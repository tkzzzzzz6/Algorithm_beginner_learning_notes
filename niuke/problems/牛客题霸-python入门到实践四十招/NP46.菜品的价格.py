# @nc app=nowcoder id=86843c3ba8f240cda3bb2b177f896735 topic=314 question=10055953 lang=Python3
# 2026-04-27 08:31:39
# https://www.nowcoder.com/practice/86843c3ba8f240cda3bb2b177f896735?tpId=314&tqId=10055953
# [NP46] 菜品的价格

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    manuscipt = {'pizza':10,'rice':2 ,'yogurt':5}

    x = input()

    if x == 'pizza':
        print(manuscipt['pizza']) 
    elif x == 'rice':
        print(manuscipt['rice'])
    elif x == 'yogurt':
        print(manuscipt['yogurt'])
    else:
        print(8)


if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
