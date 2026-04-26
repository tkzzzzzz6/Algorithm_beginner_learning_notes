'''
Author: tkzzzzzz6
Date: 2026-04-23 07:52:15
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-23 07:52:24
'''
# @nc app=nowcoder id=3236759a8bcd43819cfd2b7eb4a9eebb topic=314 question=10055851 lang=Python3
# 2026-04-23 07:52:15
# https://www.nowcoder.com/practice/3236759a8bcd43819cfd2b7eb4a9eebb?tpId=314&tqId=10055851
# [NP11] 单词的长度

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    word = input()
    print(len(word))

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
