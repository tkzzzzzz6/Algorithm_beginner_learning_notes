'''
Author: tkzzzzzz6
Date: 2026-04-27 08:03:43
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 08:03:47
'''
# @nc app=nowcoder id=c207a15115764206b06d367abda91522 topic=314 question=10055926 lang=Python3
# 2026-04-27 08:03:43
# https://www.nowcoder.com/practice/c207a15115764206b06d367abda91522?tpId=314&tqId=10055926
# [NP39] 字符串之间的比较

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    str1 = input().strip()
    str2 = input().strip()

    print(str1 == str2)
    print(str1.lower() == str2.lower())

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
