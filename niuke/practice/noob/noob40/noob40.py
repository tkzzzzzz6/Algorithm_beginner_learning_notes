import sys, math;
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

mod = int(10**9 + 7)

def solve():
    n,m = map(int,input().split())
    dp = [[1]*(m+1) for _ in range(n+1)]

    for i in range(2,n+1):
        for j in range(2,m+1):
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod
    print(dp[n][m])

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()