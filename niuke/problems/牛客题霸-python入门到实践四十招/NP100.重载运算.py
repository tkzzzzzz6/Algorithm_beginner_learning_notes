'''
Author: tkzzzzzz6
Date: 2026-04-28 09:13:45
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-28 09:17:22
'''
# @nc app=nowcoder id=342d1b8b0fe3416797bad62d22cbb51a topic=314 question=10059992 lang=Python3
# 2026-04-28 09:13:45
# https://www.nowcoder.com/practice/342d1b8b0fe3416797bad62d22cbb51a?tpId=314&tqId=10059992
# [NP100] 重载运算

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

class Coordinate:
    def __init__(self,x,y):
        self.x = x
        self.y = y

    def __str__(self):
        coord = (self.x,self.y)
        return str(coord)
    
    def __add__(c1:'Coordinate',c2:'Coordinate'):
        return Coordinate(c1.x+c2.x,c1.y+c2.y)


def solve():
    x1,y1 = map(int,input().split())
    x2,y2 = map(int,input().split())
    c1 = Coordinate(x1,y1)
    c2 = Coordinate(x2,y2)
    
    print(c1+c2)

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()

# @nc code=end
