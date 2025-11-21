import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n,x = map(int,input().split())
    cnt = 0
    for i in range(1,n+1):
        s1 = str(i)
        cnt += s1.count(str(x))

    print(cnt)
        
    

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()