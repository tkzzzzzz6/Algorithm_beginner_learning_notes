import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    
    n = int(input())
    s = str(input())

    direction = {}
    for c in s:
        direction[c] = direction.get(c,0) + 1

    ans = 0
    
    cntR = direction.get("R",0)
    cntL = direction.get("L",0)
    cntU = direction.get("U",0)
    cntD = direction.get("D",0)

    width = max(cntL, cntR) + 1
    height = max(cntU, cntD) + 1
    ans = min(width * height, n+1)

    print(ans)


if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    t = int(input())
    for _ in range(t):
        solve()