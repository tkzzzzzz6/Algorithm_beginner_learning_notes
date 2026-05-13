'''
Author: tkzzzzzz6
Date: 2026-05-12 19:22:58
LastEditors: tkzzzzzz6
LastEditTime: 2026-05-12 19:23:00
'''
# Nowcoder Compiler: Python3

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n,m = map(int,input().split())
    players = []
    for _ in range(n):
        parts = input().split()
        sid = parts[0]
        scores = list(map(int,parts[1:]))

        solved = 0
        penalty = 0
        for t in scores:
            if t > 0:
                solved += 1
                penalty += t
            

        players.append((sid,solved,penalty))


    players.sort(key = lambda x:(-x[1],x[2],x[0]))

    ans = []
    prev_solved = prev_penalty = None
    rank = 0

    for i,(sid,solved,penalty) in enumerate(players):
        if(solved != prev_solved or penalty != prev_penalty):
            rank = i + 1
            prev_solved = solved
            prev_penalty = penalty

        ans.append(f"{rank} {sid} {solved} {penalty}")

    sys.stdout.write("\n".join(ans))
    
if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()
