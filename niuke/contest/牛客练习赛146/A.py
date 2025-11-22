import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n = int(input())
    a = list(map(int,input().split()))

    total  = sum(a)
    if total % 2 == 0:
        if total > 2*n:
            print(n)
        else:
            print(total - n)
    else:
        # 假设每个机器都只有1个硬币,其他硬币进行分配
        if total > 2*n:
            print(n-1) #total一定是奇数
        else:
            print(total - n)
        

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()