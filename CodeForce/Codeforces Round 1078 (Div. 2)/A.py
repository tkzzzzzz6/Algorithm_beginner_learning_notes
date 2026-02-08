import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():

    data = sys.stdin.read().split()

    iterator = iter(data)
    t = int(next(iterator))

    out = []

    for _ in range(t):
        n = int(next(iterator))
        w = int(next(iterator))

        ans = n - (n//w)
        out.append(str(ans))

    sys.stdout.write("\n".join(out))




if __name__ == "__main__":
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()
