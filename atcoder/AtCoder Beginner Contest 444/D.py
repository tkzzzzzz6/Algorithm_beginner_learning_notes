'''
Author: tkzzzzzz6
Date: 2026-02-07 20:33:35
LastEditors: tkzzzzzz6
LastEditTime: 2026-02-07 20:39:05
'''
import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    input = sys.stdin.read().split()

    N = int(input[0])

    A = list(map(int,input[1:]))

    max_val = max(A)

    freq = [0]*(max_val+2)
    for x in A:
        freq[x] += 1

    count_ge = [0]*(max_val+2)
    cnt = 0
    for i in range(max_val,0,-1):
        cnt += freq[i]
        count_ge[i] = cnt

    ans = []
    carry = 0
    i = 1

    while i <= max_val or carry > 0:
        col_sum = carry
        if i <= max_val:
            col_sum += count_ge[i]

        ans.append(str(col_sum%10))
        carry = col_sum // 10

        i+=1
    print("".join(reversed(ans)))

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()
