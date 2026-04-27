'''
Author: tkzzzzzz6
Date: 2026-04-27 07:42:21
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 07:42:26
'''
# @nc app=nowcoder id=38187b9f30e44fdaa496751b82b0adbf topic=314 question=10055869 lang=Python3
# 2026-04-27 07:42:21
# https://www.nowcoder.com/practice/38187b9f30e44fdaa496751b82b0adbf?tpId=314&tqId=10055869
# [NP29] 用列表实现栈

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    stack = [1, 2, 3, 4, 5]
    stack.pop()
    print(stack)
    stack.pop()
    print(stack)
    x = int(input())
    stack.append(x)
    print(stack)

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
