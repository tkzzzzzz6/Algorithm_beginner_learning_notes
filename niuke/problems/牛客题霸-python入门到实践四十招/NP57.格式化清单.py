'''
Author: tkzzzzzz6
Date: 2026-04-27 09:09:20
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 09:09:25
'''
# @nc app=nowcoder id=91041d28883847d2af52e98e3df14b53 topic=314 question=10058953 lang=Python3
# 2026-04-27 09:09:20
# https://www.nowcoder.com/practice/91041d28883847d2af52e98e3df14b53?tpId=314&tqId=10058953
# [NP57] 格式化清单

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    eat_list = ['apple', 'ice cream', 'watermelon', 'chips', 'hotdogs', 'hotpot']

    while eat_list:
        eat_list.pop()
        print(eat_list)

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
