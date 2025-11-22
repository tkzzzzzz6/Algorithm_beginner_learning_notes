import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n = int(input())
    a = list(map(int,input().split()))

    for i in range(n):
        ans = -1
        for j in range(i-1,-1,-1):
            if a[j] > a[i]:
                ans = j + 1
                break
        print(ans)



if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()