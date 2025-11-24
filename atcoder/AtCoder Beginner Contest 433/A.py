import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    x, y, z = map(int, input().split())

    if z == 1:
        # (y+t)/(x+t)=1  =>  y = x  must hold
        print("Yes" if y == x else "No")
        return

    num = y - z * x
    den = z - 1

    if num % den == 0:
        t = num // den
        print("Yes" if t >= 0 else "No")
    else:
        print("No")

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()