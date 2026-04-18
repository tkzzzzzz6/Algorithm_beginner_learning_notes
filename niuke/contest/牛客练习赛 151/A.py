# Nowcoder Compiler: Python3
import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n,k = map(int,input().split())
    ans = 0
    a = list(map(int,input().split()))
    for x in a:
        if x % k == 1% k:
            ans += 1
    print(ans)

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()
