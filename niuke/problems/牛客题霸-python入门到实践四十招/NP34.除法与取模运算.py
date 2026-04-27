'''
Author: tkzzzzzz6
Date: 2026-04-27 07:51:38
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 07:53:46
'''
# @nc app=nowcoder id=9fe22ac9e55448f4920886f84efeac58 topic=314 question=10055876 lang=Python3
# 2026-04-27 07:51:38
# https://www.nowcoder.com/practice/9fe22ac9e55448f4920886f84efeac58?tpId=314&tqId=10055876
# [NP34] 除法与取模运算

# @nc code=start


import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    x = int(input())
    y = int(input())

    if y != 0:
        print(f"{x//y} {x%y}")
        print(f"{x/y:.2f}")

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
