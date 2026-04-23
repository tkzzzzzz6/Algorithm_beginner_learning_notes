'''
Author: tkzzzzzz6
Date: 2026-04-22 22:23:13
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-22 22:23:17
'''
# @nc app=nowcoder id=38c0553bf56c4ad9b330df4800249a39 topic=314 question=10055863 lang=Python3
# 2026-04-22 22:23:13
# https://www.nowcoder.com/practice/38c0553bf56c4ad9b330df4800249a39?tpId=314&tqId=10055863
# [NP22] 删除简历

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    names = input().split()
    del names[0]

    print(names)

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
