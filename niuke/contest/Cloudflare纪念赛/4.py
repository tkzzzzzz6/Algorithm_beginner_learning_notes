import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n,k = map(int,input().split())
    s = str(input())

    runs =[]
    cnt = 1
    for i in range(1,n):
        if s[i] == s[i-1]:
            cnt += 1
        else:
            runs.append(cnt)
            cnt = 1
    runs.append(cnt)

    if k == 1:
        ans = sum(len*(len + 1)//2 for len in runs)
    else:
        ans = 0
        m = len(runs)
        if k <= m:
            for i in range(m-k + 1):
                ans += runs[i]*runs[i+k-1]
        else:
            ans = 0

    print(ans)
    

if __name__ == "__main__":
    solve()