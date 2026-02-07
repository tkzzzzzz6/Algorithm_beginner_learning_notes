import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    print("Yes" if len(set(input())) == 1 else "No")

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()
