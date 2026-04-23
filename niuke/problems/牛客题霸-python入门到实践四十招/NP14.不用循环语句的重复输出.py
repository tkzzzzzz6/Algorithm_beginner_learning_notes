'''
Author: tkzzzzzz6
Date: 2026-04-23 07:59:22
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-23 07:59:28
'''
# @nc app=nowcoder id=9baca399143e418cb471159d3b96743e topic=314 question=10055852 lang=Python3
# 2026-04-23 07:59:22
# https://www.nowcoder.com/practice/9baca399143e418cb471159d3b96743e?tpId=314&tqId=10055852
# [NP14] 不用循环语句的重复输出

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    name = input()
    for _ in range(100):
        print(name,end='')

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
