import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n = int(input())
    fac = [1]
    for i in range(1,31):
        if fac[-1] * i > 10**9:
            break
        fac.append(fac[-1]*i)
    mn = abs(n)
    res_x = 1
    res_y = 1
    def calc(x: int, y: int) -> None:
        if y <= 0 or y == 2:
            return
        nonlocal mn, res_x, res_y
        if abs((fac[x]-1)*y-n) < mn:
            mn = abs((fac[x]-1)*y-n)
            res_x = x
            res_y = y

    for x in range(3, len(fac)):
        y = n // (fac[x]-1)
        calc(x, y)
        calc(x, y+1)
        calc(x, y-1)
    print(res_x, res_y)

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()
