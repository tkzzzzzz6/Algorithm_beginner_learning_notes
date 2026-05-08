'''
Author: tkzzzzzz6
Date: 2026-04-27 22:47:45
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 22:47:50
'''
# @nc app=nowcoder id=a69d651105ee4cfd86c56418f0aa9de3 topic=314 question=10059462 lang=Python3
# 2026-04-27 22:47:45
# https://www.nowcoder.com/practice/a69d651105ee4cfd86c56418f0aa9de3?tpId=314&tqId=10059462
# [NP74] 字典新增

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    note_dict = {'a': ['apple', 'abandon', 'ant'], 'b': ['banana', 'bee', 'become'], 'c': ['cat', 'come'], 'd': 'down'}
    letter = input()
    word = input()

    note_dict[letter] = word

    print(note_dict)

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
