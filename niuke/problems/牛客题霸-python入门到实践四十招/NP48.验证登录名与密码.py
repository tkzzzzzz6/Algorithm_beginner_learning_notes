'''
Author: tkzzzzzz6
Date: 2026-04-27 08:45:11
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 08:47:16
'''
# @nc app=nowcoder id=f3517fb21fd34d3880bd41454ca7209f topic=314 question=10055956 lang=Python3
# 2026-04-27 08:45:11
# https://www.nowcoder.com/practice/f3517fb21fd34d3880bd41454ca7209f?tpId=314&tqId=10055956
# [NP48] 验证登录名与密码

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    userId = input().strip()
    password = input().strip()

    if userId == 'admis' and password == 'Nowcoder666':
        print("Welcome!")
    else:
        print("user id or password is not correct!")

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()

# @nc code=end
