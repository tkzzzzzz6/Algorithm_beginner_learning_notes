'''
Author: tkzzzzzz6
Date: 2026-04-27 09:02:18
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 09:02:21
'''
# @nc app=nowcoder id=ea64853bae7045f5a2fb1feaf64832dd topic=314 question=2367300 lang=Python3
# 2026-04-27 09:02:18
# https://www.nowcoder.com/practice/ea64853bae7045f5a2fb1feaf64832dd?tpId=314&tqId=2367300
# [NP54] 被5整除的数字

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    my_list = list(range(5,51,5))

    for x in my_list:
        print(x)

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
