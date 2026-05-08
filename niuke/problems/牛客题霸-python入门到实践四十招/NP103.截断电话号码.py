'''
Author: tkzzzzzz6
Date: 2026-04-28 09:31:10
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-28 09:37:12
'''
# @nc app=nowcoder id=078d1abcb55648f687a78d87e4b3cb69 topic=314 question=10060020 lang=Python3
# 2026-04-28 09:31:10
# https://www.nowcoder.com/practice/078d1abcb55648f687a78d87e4b3cb69?tpId=314&tqId=10060020
# [NP103] 截断电话号码

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
import re
input = lambda: sys.stdin.readline().rstrip()

def solve():
    s = input().strip()
    m = re.match(r'^[\d-]+',s)
    print(m.group())

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
