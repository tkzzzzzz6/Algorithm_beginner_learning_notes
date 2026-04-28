'''
Author: tkzzzzzz6
Date: 2026-04-28 08:08:27
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-28 08:08:31
'''
# @nc app=nowcoder id=48b79127550b478bbdc828d022a54e86 topic=314 question=10059747 lang=Python3
# 2026-04-28 08:08:27
# https://www.nowcoder.com/practice/48b79127550b478bbdc828d022a54e86?tpId=314&tqId=10059747
# [NP86] 字符子串的查找

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    long_str = input()
    print(long_str.find('NiuNiu'))

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
