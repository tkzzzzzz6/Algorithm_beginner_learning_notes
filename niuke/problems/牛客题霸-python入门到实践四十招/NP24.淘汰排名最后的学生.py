'''
Author: tkzzzzzz6
Date: 2026-04-22 22:35:12
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-22 22:35:32
'''
# @nc app=nowcoder id=d7cc81fa615c4231b5f86c97e5b275b4 topic=314 question=10055865 lang=Python3
# 2026-04-22 22:35:12
# https://www.nowcoder.com/practice/d7cc81fa615c4231b5f86c97e5b275b4?tpId=314&tqId=10055865
# [NP24] 淘汰排名最后的学生

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    students = list(input().split())

    if(len(students) < 3):
        return -1

    for _ in range(3):
        students.pop()

    print(students)
if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
