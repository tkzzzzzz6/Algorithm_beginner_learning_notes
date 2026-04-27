'''
Author: tkzzzzzz6
Date: 2026-04-27 07:44:20
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 07:45:54
'''
# @nc app=nowcoder id=cc9e56e0d80d44e5990f76196adb4912 topic=314 question=10055870 lang=Python3
# 2026-04-27 07:44:20
# https://www.nowcoder.com/practice/cc9e56e0d80d44e5990f76196adb4912?tpId=314&tqId=10055870
# [NP30] 用列表实现队列

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    queue = [1, 2, 3, 4, 5] 
    queue.pop(0)
    print(queue)
    queue.pop(0)
    print(queue)
    x = int(input())
    queue.append(x)
    print(queue)

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
