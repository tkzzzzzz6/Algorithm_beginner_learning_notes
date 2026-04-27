'''
Author: tkzzzzzz6
Date: 2026-04-27 09:17:20
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 09:30:34
'''
# @nc app=nowcoder id=730b90507602412fac90a3f106bfa0cd topic=314 question=10059169 lang=Python3
# 2026-04-27 09:17:20
# https://www.nowcoder.com/practice/730b90507602412fac90a3f106bfa0cd?tpId=314&tqId=10059169
# [NP61] 牛牛的矩阵相加

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    my_matrix = [
        [1,2,3],
        [4,5,6],
        [7,8,9]
    ]

    n = int(input())

    ans = [[x*n for x in row] for row in my_matrix]
    
    print(ans)

# def solve():
#     n = int(input())

#     mat = [
#         [1, 2, 3],
#         [4, 5, 6],
#         [7, 8, 9]
#     ]

#     rows = len(mat)
#     cols = len(mat[0])

#     flat = [x for row in mat for x in row]

#     flat = [x*n for x in flat]

#     ans = [flat[i*cols:(i+1) * cols] for i in range(rows)]

#     print(ans)


if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
