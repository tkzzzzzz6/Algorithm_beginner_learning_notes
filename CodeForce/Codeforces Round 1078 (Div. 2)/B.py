'''
Author: tkzzzzzz6
Date: 2026-02-08 17:41:25
LastEditors: tkzzzzzz6
LastEditTime: 2026-02-08 17:55:44
'''
import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect

def solve():
    line = input()
    n,x,y = map(int,line.split())

    a = []
    while(len(a) < n):
        a.extend(map(int,input().split()))

    floors = [v// x for v in a]
    S = sum(floors)

    best = 0
    for v,f in zip(a,floors):
        cand = v + (S-f)*y    
        if cand > best:
            best = cand

    out.append(str(best))


if __name__ == "__main__":
    t = int(input())
    out = []
    for _ in range(t):
        solve()
    
    sys.stdout.write("\n".join(out))
