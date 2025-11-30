import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n = int(input())
    A = [0,1,1]
    for i in range(4,n+1):
        new = A[0] + 2*A[1] + A[2]
        A[0] = A[1]
        A[1] = A[2]
        A[2] = new
    print(A[2])

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()