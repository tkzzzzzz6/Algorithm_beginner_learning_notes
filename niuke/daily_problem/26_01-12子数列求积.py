import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n = int(input())
    arr = list(map(int,input().split()))
    arr.sort()

    if arr[-1] > n:
        print(-1)
        return

    elif arr[-1] == n:
        print(1)
        return
    else:
        arr = arr[:-arr[-1]]
        n = len(arr)
        # dp[i]表示用i+1个乐手组乐队的结果
        dp = [0]*n
        dp[0] = 1 if arr[0] == 1 else 0
        for i in range(1,n):
            if arr[i] <= i + 1:
                dp[i] = max(dp[i-1],dp[i-arr[i]]+1)
        print(dp[-1]+1)



if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()
