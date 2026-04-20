# Nowcoder Compiler: Python3
import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

# x > a时,a%k = a
# x <= a 时,a%k = k;

def solve():
    n = int(input())
    a = list(map(int,input().split()))
    prev = -1

    for x in a:
        ms = (x-1) // 2
        if ms > prev:
            prev += 1
        elif x > prev:
            prev = x
        else:
            print("NO\n")
            return
    print("YES\n")

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()
