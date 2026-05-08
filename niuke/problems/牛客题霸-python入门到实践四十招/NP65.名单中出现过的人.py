# @nc app=nowcoder id=d70f0bbba1bb4683a8789e86c0978f01 topic=314 question=10059187 lang=Python3
# 2026-04-27 09:39:57
# https://www.nowcoder.com/practice/d70f0bbba1bb4683a8789e86c0978f01?tpId=314&tqId=10059187
# [NP65] 名单中出现过的人

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    secret_list = ['Tom', 'Tony', 'Allen', 'Cydin', 'Lucy', 'Anna']
    secret_tuple = tuple(secret_list)
    print(secret_tuple)

    name = input()
    if name in  secret_tuple:
        print('Congratulations!')
    else:
        print('What a pity!')

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
