'''
Author: tkzzzzzz6
Date: 2026-04-26 20:13:26
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-26 20:15:05
'''
# @nc app=nowcoder id=c62ef46892ef4c478802df983f8624b7 topic=314 question=2549745 lang=Python3
# 2026-04-26 20:13:26
# https://www.nowcoder.com/practice/c62ef46892ef4c478802df983f8624b7?tpId=314&tqId=2549745
# [NP27] 朋友们的喜好

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    res = []
    name = ['Niumei', 'YOLO', 'Niu Ke Le', 'Mona']
    food = ['pizza', 'fish', 'potato', 'beef']
    nums = [3, 6, 0, 3]

    res.append(name)
    res.append(food)
    res.append(nums)

    print(res)

if __name__ == "__main__":
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
