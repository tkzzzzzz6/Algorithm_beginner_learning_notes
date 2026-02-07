'''
Author: tkzzzzzz6
Date: 2026-02-07 20:05:10
LastEditors: tkzzzzzz6
LastEditTime: 2026-02-07 20:10:28
'''
import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    input = sys.stdin.read().split()

    N = int(input[0])
    K = int(input[1])

    ans = 0

    for i in range(1,N+1):
        current_n = i
        digit_sum = 0
        while current_n > 0:
            digit_sum += current_n % 10
            current_n //= 10
        
        if digit_sum == K:
            ans += 1

    print(ans)


if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()
