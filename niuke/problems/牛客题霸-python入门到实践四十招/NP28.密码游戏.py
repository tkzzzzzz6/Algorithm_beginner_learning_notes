'''
Author: tkzzzzzz6
Date: 2026-04-26 20:15:54
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-26 20:16:05
'''
# @nc app=nowcoder id=36641ab168664384aff798ba7ce34bc1 topic=314 question=2583410 lang=Python3
# 2026-04-26 20:15:54
# https://www.nowcoder.com/practice/36641ab168664384aff798ba7ce34bc1?tpId=314&tqId=2583410
# [NP28] 密码游戏

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    s = input().strip()
    a = [str((int(c) + 3)%9) for c in s]
    a[0],a[2] = a[2],a[0]
    a[3],a[1] = a[1],a[3]

    print("".join(a))

    

if __name__ == "__main__":
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
