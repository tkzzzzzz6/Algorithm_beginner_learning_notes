'''
Author: tkzzzzzz6
Date: 2026-04-28 08:23:30
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-28 08:32:57
'''
# @nc app=nowcoder id=8783056676de4396b0bf816a3561d62f topic=314 question=10059952 lang=Python3
# 2026-04-28 08:23:30
# https://www.nowcoder.com/practice/8783056676de4396b0bf816a3561d62f?tpId=314&tqId=10059952
# [NP95] 兔子的数量

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def f(n):
    if n == 1:
        return 2
    if n == 2:
        return 3
    fibonaci = [2,3]
    for i in range(2,n):
        fibonaci.append(fibonaci[-1]+fibonaci[-2])

    return fibonaci[-1]
    
def solve():
    n = int(input())
    print(f(n))

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
