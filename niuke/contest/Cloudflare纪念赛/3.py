import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
# input = lambda: sys.stdin.readline().rstrip()

def solve():
    n = int(input())

    a = str(input())

    if len(a)&1 == 1: #奇数
        print(-1)
        return

    cnt = 0
    res = 0
    for c in a:
        if c == "(":
            cnt += 1
        else:
            cnt -= 1
            if cnt == -1:
                res += 1
                cnt = 1
    
    if(cnt > 0):
        res += cnt // 2

    print(res)



if __name__ == "__main__":
    solve()