'''
Author: tkzzzzzz6
Date: 2026-04-27 07:46:30
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 07:46:43
'''
# @nc app=nowcoder id=113a0507b1144fa9a602c2a3cd847205 topic=314 question=2367361 lang=Python3
# 2026-04-27 07:46:30
# https://www.nowcoder.com/practice/113a0507b1144fa9a602c2a3cd847205?tpId=314&tqId=2367361
# [NP31] 团队分组

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    group_list = [ 'Tom', 'Allen', 'Jane', 'William', 'Tony' ]
    print(group_list[:2])
    print(group_list[1:4])
    print(group_list[-2:])

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
