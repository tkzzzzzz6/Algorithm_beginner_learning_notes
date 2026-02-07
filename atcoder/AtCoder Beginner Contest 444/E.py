'''
Author: tkzzzzzz6
Date: 2026-02-07 20:41:10
LastEditors: tkzzzzzz6
LastEditTime: 2026-02-07 21:03:43
'''
import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect

input = lambda: sys.stdin.readline().rstrip()

def solve():
    input = sys.stdin.read().split()
    N = int(input[0])
    D = int(input[1])
    A = list(map(int,input[2:]))

    unique_vals = sorted(list(set(A)))
    M = len(unique_vals)

    rank_map = {v:i for i,v in enumerate(unique_vals)}
    ranks = [rank_map[x] for x in A]

    size = 1
    while size < M:
        size *= 2
    tree = [-1]*(2*size)

    L = 0
    res = 0
    bs_left = bisect.bisect_left

    def update(rank,idx):
        pos = rank + size
        tree[pos] = idx
        while pos > 1:
            pos //= 2
            tree[pos] = max(tree[2*pos],tree[2*pos+1])

    def query(l,r):
        l += size
        r += size
        ans = -1

        while l<=r:
            if l % 2 ==1:
                ans = max(ans,tree[l])
                l+=1
            if r % 2 == 0:
                ans = max(ans,tree[r])
                r -= 1
            l //=2
            r //= 2
        return ans


    for R in range(N):
        val = A[R]
        val_rank = ranks[R]

        q_l = bs_left(unique_vals,val-D+1)
        q_r = bs_left(unique_vals,val+D)

        l,r = q_l+size,q_r+size
        max_conflict_idx = -1

        while l < r:
            if l&1:
                if tree[l] > max_conflict_idx:
                    max_conflict_idx = tree[l]
                l += 1
            if r&1:
                r -= 1
                if tree[r] > max_conflict_idx:
                    max_conflict_idx = tree[r]
            l >>=1
            r >>= 1

        if max_conflict_idx != -1:
            if max_conflict_idx+1>L:
                L = max_conflict_idx+1

        res += (R-L+1)

        idx = val_rank+size
        tree[idx] = R
        while idx > 1:
            idx >>= 1
            left_child = tree[idx << 1]
            right_child = tree[(idx << 1) | 1]
            tree[idx] = max(left_child,right_child)

    print(res)



if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()
