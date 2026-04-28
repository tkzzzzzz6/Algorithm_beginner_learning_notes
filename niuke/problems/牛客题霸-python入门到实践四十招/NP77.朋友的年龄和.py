'''
Author: tkzzzzzz6
Date: 2026-04-28 07:22:09
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-28 07:22:31
'''
# @nc app=nowcoder id=ba214c26c59d4349bab569b9d32bc588 topic=314 question=10059632 lang=Python3
# 2026-04-28 07:22:09
# https://www.nowcoder.com/practice/ba214c26c59d4349bab569b9d32bc588?tpId=314&tqId=10059632
# [NP77] 朋友的年龄和

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    ages = [int(x) for x in input().split()]

    # print(type(input().split()))

    print(sum(ages))

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
