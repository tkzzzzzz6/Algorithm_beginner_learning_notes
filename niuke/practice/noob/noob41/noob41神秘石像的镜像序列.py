import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    info = []
    for x in map(int,input().split()):
        if x == 0:
            break
        else:
            info.append(x)

    info_reverse = info[::-1]

    for x in info_reverse:
        print(x,end=' ')

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()