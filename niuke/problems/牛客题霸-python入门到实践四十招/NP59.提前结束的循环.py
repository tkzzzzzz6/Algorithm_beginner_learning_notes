'''
Author: tkzzzzzz6
Date: 2026-04-27 09:12:55
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 09:14:00
'''
# @nc app=nowcoder id=b957171b6e974fb0b5dd3ef653624b52 topic=314 question=10058954 lang=Python3
# 2026-04-27 09:12:55
# https://www.nowcoder.com/practice/b957171b6e974fb0b5dd3ef653624b52?tpId=314&tqId=10058954
# [NP59] 提前结束的循环

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    my_list = [3, 45, 9, 8, 12, 89, 103, 42, 54, 79]

    x = int(input())
    for n in my_list:
        if x == n:
            break
        else:
            print(n)

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
