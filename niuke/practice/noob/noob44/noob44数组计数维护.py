import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n,k = map(int,input().split())
    a = list(map(int,input().split()))

    s = cnt = 0
    for i in range(n):
        if a[i] >= k:
            s+=a[i]
        elif a[i] == 0 and s >= 1:
            s -= 1
            cnt += 1
        else:
            continue
    print(cnt)

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    t = int(input())
    for _ in range(t):
        solve()