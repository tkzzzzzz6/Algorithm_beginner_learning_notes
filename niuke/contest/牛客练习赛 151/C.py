'''
Author: tkzzzzzz6
Date: 2026-04-17 20:20:56
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-17 20:46:39
'''
# Nowcoder Compiler: Python3
import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n,q = map(int,input().split())
    a = list(map(int,input().split()))
    b = sorted(a)

    s = [] #收集被错误排序的元素
    for i in range(n):
        if a[i] != b[i]:
            s.append(a[i])

    if not s: #原始数组本来有序
        for _ in range(q):
            input()
            print("Yes")
        return
    
    s.sort()
    mn,mx = s[0],s[-1]

    for _ in range(q):
        x = int(input())
        if mx*mn >= x:
            print("Yes")
        else:
            print("No")


if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()
