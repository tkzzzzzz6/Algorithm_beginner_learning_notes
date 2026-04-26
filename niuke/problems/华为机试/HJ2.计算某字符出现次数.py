'''
Author: tkzzzzzz6
Date: 2026-04-26 19:45:14
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-26 20:10:59
'''
# @nc app=nowcoder id=a35ce98431874e3a820dbe4b2d0508b1 topic=37 question=21225 lang=Python3
# 2026-04-26 19:45:14
# https://www.nowcoder.com/practice/a35ce98431874e3a820dbe4b2d0508b1?tpId=37&tqId=21225
# [HJ2] 计算某字符出现次数

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    s = input().lower()
    c = input().lower()
    cnt = {}
    print(s.count(c))

if __name__ == "__main__":
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
