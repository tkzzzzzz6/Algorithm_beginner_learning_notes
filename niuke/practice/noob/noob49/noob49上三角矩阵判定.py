import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n,m = map(int,input().split())
    transpose = [[0] * n for _ in range(m)]

    for i in range(n):
        row = list(map(int,input().split()))
        for j in range(m):
            transpose[j][i] = row[j]

    for i in range(m):
        for j in range(n):
            print(transpose[i][j],end=' ')
        print()


if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()