'''
Author: tkzzzzzz6
Date: 2026-04-28 08:15:56
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-28 08:16:12
'''
# @nc app=nowcoder id=efc02a6e769a4dc3b1433a36109c9217 topic=314 question=10059751 lang=Python3
# 2026-04-28 08:15:56
# https://www.nowcoder.com/practice/efc02a6e769a4dc3b1433a36109c9217?tpId=314&tqId=10059751
# [NP90] 修正错误的字母

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    str = input()
    print(str.replace('a*','ab'))

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
