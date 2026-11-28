import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n,c = map(int,input().split())
    len_c = len(str(c))

    n = n - len_c - 2
    cnt = 0

    for a in range(c+1):
        b = c - a
        if b < 0:
            continue
        if(len(str(a)) + len(str(b))) == n:
            cnt += 1
    print(cnt)

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()