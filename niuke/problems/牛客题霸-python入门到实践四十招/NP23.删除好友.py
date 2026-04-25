# @nc app=nowcoder id=656f7d09fe9c4d78919e7cc2b4a19c81 topic=314 question=10055864 lang=Python3
# 2026-04-22 22:28:49
# https://www.nowcoder.com/practice/656f7d09fe9c4d78919e7cc2b4a19c81?tpId=314&tqId=10055864
# [NP23] 删除好友

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    friends = input().split()
    remove_friends_name = input()

    if remove_friends_name in friends:
        friends.remove(remove_friends_name)
    print(friends)

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()

# @nc code=end
