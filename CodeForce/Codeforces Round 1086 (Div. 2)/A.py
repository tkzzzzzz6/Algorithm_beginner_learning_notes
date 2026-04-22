import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n = int(input())
    counts = {}
    for _ in range(n):
        r = list(map(int,input().split()))
        for c in r:
            counts[c] = counts.get(c,0)+1

    limit = n*n - n

    ok = True
    for color in counts:
        if counts[color] > limit:
            ok = False
            break

    print("YES" if ok else "NO")
if __name__ == "__main__":
    # sys.setrecursionlimit(10**7)
    t = int(input())
    for _ in range(t):
        solve()
