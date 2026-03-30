import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n = int(input())
    print("YES" if n % 2 == 0 and n > 2 else "NO")

if __name__ == "__main__":
    # sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()
