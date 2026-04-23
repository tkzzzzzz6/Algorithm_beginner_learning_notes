# @nc app=nowcoder id=0454d1bd28cd499ba06afdabe0fb9caf topic=314 question=10055839 lang=Python3
# 2026-04-23 07:45:56
# https://www.nowcoder.com/practice/0454d1bd28cd499ba06afdabe0fb9caf?tpId=314&tqId=10055839
# [NP6] 牛牛的小数输出

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    f = float(input())
    # print(f"{f:.2f}")
    print("{:.2f}".format(f))

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
