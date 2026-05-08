'''
Author: tkzzzzzz6
Date: 2026-04-27 22:38:36
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 22:43:56
'''
# @nc app=nowcoder id=f3b6bfd4a411431b96f08bd153a51659 topic=314 question=10059234 lang=Python3
# 2026-04-27 22:38:36
# https://www.nowcoder.com/practice/f3b6bfd4a411431b96f08bd153a51659?tpId=314&tqId=10059234
# [NP72] 生成字典

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    names_list = input().split()
    language_list = input().split()

    n_l_dict = dict(zip(names_list,language_list))
    
    print(n_l_dict)


if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
