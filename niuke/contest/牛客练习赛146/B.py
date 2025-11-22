import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n,t = map(int,input().split())
    h = list(map(int,input().split()))
    v = list(map(int,input().split()))

    xs = [int(input()) for _ in range(t)]

    xs_sorted = sorted(xs)

    ptr = n - 1

    best1,best2 = 0,0
    ans = 0

    for x in xs_sorted:
        while ptr >= 0 and h[ptr] < x:
            val = v[ptr]
            if val >= best1:
                best2 = best1
                best1 = val
            elif val >= best2:
                best2 = val
            ptr-=1
        ans += best1 + best2
    print(ans)

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()