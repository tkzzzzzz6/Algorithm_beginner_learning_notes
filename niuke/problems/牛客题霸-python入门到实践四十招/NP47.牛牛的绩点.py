'''
Author: tkzzzzzz6
Date: 2026-04-27 08:36:03
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 08:42:09
'''
# @nc app=nowcoder id=de8bc3e736164786b07a4dd64ed172f7 topic=314 question=2577215 lang=Python3
# 2026-04-27 08:36:03
# https://www.nowcoder.com/practice/de8bc3e736164786b07a4dd64ed172f7?tpId=314&tqId=2577215
# [NP47] 牛牛的绩点

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    grade_map = {
        "A":4.0,
        "B":3.0,
        "C":2.0,
        "D":1.0,
        "F":0
    }

    credit_sum = 0
    sum = 0
    while True:
        grade = input()
        if grade == "False":
            break
        credit = float(input().strip())
        credit_sum += credit
        sum += grade_map[grade]*credit

    print(f"{(sum / credit_sum):.2f}")



if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
