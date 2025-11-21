import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n,k,m = map(int,input().split())

    ans = [i for i in range(1,n+1)]
    idx = k-1
    while len(ans) > 1:
        idx = (idx + m - 1)%len(ans)
        ans.pop(idx)
    print(ans[0])

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()