'''
Author: tkzzzzzz6
Date: 2026-04-22 22:37:36
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-22 22:38:00
'''
# @nc app=nowcoder id=855d960ba868480ba6e626914018ded4 topic=314 question=10055866 lang=Python3
# 2026-04-22 22:37:36
# https://www.nowcoder.com/practice/855d960ba868480ba6e626914018ded4?tpId=314&tqId=10055866
# [NP25] 有序的列表

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    my_list = ['P','y','t','h','o','n']

    print(sorted(my_list))
    print(my_list)
    my_list.sort(reverse=True)
    print(my_list)


if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
