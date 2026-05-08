'''
Author: tkzzzzzz6
Date: 2026-04-27 23:07:03
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-28 09:30:49
'''
# @nc app=nowcoder id=6e25b95632e6433db4b5053f91138cb5 topic=314 question=10060019 lang=Python3
# 2026-04-27 23:07:03
# https://www.nowcoder.com/practice/6e25b95632e6433db4b5053f91138cb5?tpId=314&tqId=10060019
# [NP102] 提取数字电话

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
import re
input = lambda: sys.stdin.readline().rstrip()

def solve():
    p = input().strip()
    # res = re.sub(r'[^0-9]','',p)
    res = re.sub(r'\D','',p)
    print(res)


if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
