'''
Author: tkzzzzzz6
Date: 2026-04-27 09:10:55
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 09:10:59
'''
# @nc app=nowcoder id=bfd85733e4de4d1da8d756712e289dac topic=314 question=2368127 lang=Python3
# 2026-04-27 09:10:55
# https://www.nowcoder.com/practice/bfd85733e4de4d1da8d756712e289dac?tpId=314&tqId=2368127
# [NP58] 找到HR

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    users_list = ['Niuniu','Niumei','HR','Niu Ke Le','GURR' , 'LOLO' ]

    for x in users_list:
        if x == 'HR':
            print(f"Hi, {x}! Would you like to hire someone?")
        else:
            print(f"Hi, {x}! Welcome to Nowcoder!")

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
