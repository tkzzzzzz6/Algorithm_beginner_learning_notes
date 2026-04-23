'''
Author: tkzzzzzz6
Date: 2026-04-22 22:02:35
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-22 22:02:46
'''
# @nc app=nowcoder id=a82efa7714e9466b9f9e1020b4da2b45 topic=314 question=10055828 lang=Python3
# 2026-04-22 22:02:35
# https://www.nowcoder.com/practice/a82efa7714e9466b9f9e1020b4da2b45?tpId=314&tqId=10055828
# [NP4] 读入整数数字

# @nc code=start
import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    num = int(input())
    print(num)
    print(type(num))

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
