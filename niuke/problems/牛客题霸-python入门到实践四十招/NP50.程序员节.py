'''
Author: tkzzzzzz6
Date: 2026-04-27 08:49:59
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 08:50:03
'''
# @nc app=nowcoder id=14c705cc5ee249f98894e9ec9f8d9f29 topic=314 question=2366772 lang=Python3
# 2026-04-27 08:49:59
# https://www.nowcoder.com/practice/14c705cc5ee249f98894e9ec9f8d9f29?tpId=314&tqId=2366772
# [NP50] 程序员节

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    users_list = [ 'Niuniu' ,'Niumei' , 'Niu Ke Le' ]

    for name in users_list:
        print(f"Hi, {name}! Welcome to Nowcoder!")
    
    print("Happy Programmers' Day to everyone!")


if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
