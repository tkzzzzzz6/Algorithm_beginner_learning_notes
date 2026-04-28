'''
Author: tkzzzzzz6
Date: 2026-04-28 08:09:41
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-28 08:10:18
'''
# @nc app=nowcoder id=f7f7734369534fd7b322033fde39ee6a topic=314 question=10059853 lang=Python3
# 2026-04-28 08:09:41
# https://www.nowcoder.com/practice/f7f7734369534fd7b322033fde39ee6a?tpId=314&tqId=10059853
# [NP87] 子串的数量

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    str = input()
    print(str.count('Niu'))

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
