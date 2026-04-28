'''
Author: tkzzzzzz6
Date: 2026-04-28 08:11:31
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-28 08:15:46
'''
# @nc app=nowcoder id=c0c7fa7523ea4651bd56b6cbc8c65c66 topic=314 question=10059749 lang=Python3
# 2026-04-28 08:11:31
# https://www.nowcoder.com/practice/c0c7fa7523ea4651bd56b6cbc8c65c66?tpId=314&tqId=10059749
# [NP89] 单词造句

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    words = []
    while True:
        s = input().strip()
        if s == '0':
            break
        words.append(s)

    res = ' '.join(words)
    print(res)


if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
