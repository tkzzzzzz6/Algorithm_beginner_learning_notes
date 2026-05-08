'''
Author: tkzzzzzz6
Date: 2026-04-28 09:24:20
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-28 09:24:25
'''
# @nc app=nowcoder id=d22cc21332c24d7ea1dae179025b8cf5 topic=314 question=10060018 lang=Python3
# 2026-04-28 09:24:20
# https://www.nowcoder.com/practice/d22cc21332c24d7ea1dae179025b8cf5?tpId=314&tqId=10060018
# [NP101] 正则查找网址

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
import re
input = lambda: sys.stdin.readline().rstrip()

def solve():
    url = input()
    pattern = f'https://www'

    m = re.match(pattern,url)
    if m:
        print(m.span())
    else:
        print(0,0)


if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
