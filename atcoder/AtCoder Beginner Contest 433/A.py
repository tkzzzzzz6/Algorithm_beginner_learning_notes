import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    x,y,z = map(int,input().split())
    # y+t/x+t = 1 + y / (x+t) = z
    # t = y / (z-1) -x
    if (x - z * y) % (z - 1) == 0:
        t = (x - z * y) // (z - 1)
        if t >= 0:
            print("Yes")
        else:
            print("No")
    else:
        print("No")

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()