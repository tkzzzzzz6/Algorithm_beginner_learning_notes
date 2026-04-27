# @nc app=nowcoder id=4fbfd49326934c1d850ba4e90bc41129 topic=314 question=10055877 lang=Python3
# 2026-04-27 07:54:37
# https://www.nowcoder.com/practice/4fbfd49326934c1d850ba4e90bc41129?tpId=314&tqId=10055877
# [NP35] 朋友的年龄是否相等

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    ages = list(map(int,input().strip().split()))
    print(True if ages[0] == ages[1] else False)

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
