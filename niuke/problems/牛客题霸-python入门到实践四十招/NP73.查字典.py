'''
Author: tkzzzzzz6
Date: 2026-04-27 22:45:39
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 22:45:44
'''
# @nc app=nowcoder id=ee9c1157f07440f68c86e54a2613a927 topic=314 question=10059253 lang=Python3
# 2026-04-27 22:45:39
# https://www.nowcoder.com/practice/ee9c1157f07440f68c86e54a2613a927?tpId=314&tqId=10059253
# [NP73] 查字典

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    note_dict = {'a': ['apple', 'abandon', 'ant'], 'b': ['banana', 'bee', 'become'], 'c': ['cat', 'come'], 'd': 'down'}

    c = input()

    if c not in note_dict.keys():
        print(f"{c} not in dict")
    else:
        for x in note_dict[c]:
            print(x,end=' ')

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()

# @nc code=end
