import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n = int(input())
    a = list(map(int,input().split()))

    dp = [0] *(n+1)

    for i in range(3,n+1):
        op1 = dp[i-1] #skip
        op2 = dp[i-3] + a[i-2] #take
        dp[i] = max(op1,op2)
        

    print(dp[n])
    
if __name__ == "__main__":

    solve()