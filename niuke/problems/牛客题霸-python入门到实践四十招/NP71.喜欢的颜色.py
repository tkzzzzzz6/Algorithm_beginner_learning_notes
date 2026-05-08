'''
Author: tkzzzzzz6
Date: 2026-04-27 22:35:28
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 22:36:34
'''
# @nc app=nowcoder id=9e30a663659e4953a55ab3441d88ac92 topic=314 question=2368668 lang=Python3
# 2026-04-27 22:35:28
# https://www.nowcoder.com/practice/9e30a663659e4953a55ab3441d88ac92?tpId=314&tqId=2368668
# [NP71] 喜欢的颜色

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    result_dict = {
        'Allen': ['red', 'blue', 'yellow'],
        'Tom': ['green', 'white', 'blue'],
        'Andy': ['black', 'pink']
    }

    for student in sorted(result_dict):
        print(f"{student}'s favorite colors are:")
        for color in result_dict[student]:
            print(color)

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
