'''
Author: tkzzzzzz6
Date: 2026-04-28 07:33:39
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-28 08:07:38
'''
# @nc app=nowcoder id=896d9090983e46fe82ec35e816c1e023 topic=314 question=10059719 lang=Python3
# 2026-04-28 07:33:39
# https://www.nowcoder.com/practice/896d9090983e46fe82ec35e816c1e023?tpId=314&tqId=10059719
# [NP85] 字符的类型比较

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    s = input()
    print(s.isalpha())
    print(s.isdigit())
    print(s.isspace())

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
