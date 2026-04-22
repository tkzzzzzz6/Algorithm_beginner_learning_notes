# @nc app=nowcoder id=e641566c6a5d4020aa7a2f9e41ff125f topic=314 question=10055867 lang=Python3
# 2026-04-22 22:41:30
# https://www.nowcoder.com/practice/e641566c6a5d4020aa7a2f9e41ff125f?tpId=314&tqId=10055867
# [NP26] 牛牛的反转列表

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    num = [3, 5, 9, 0, 1, 9, 0, 3]
    num.reverse()
    print(num)

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
