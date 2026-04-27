'''
Author: tkzzzzzz6
Date: 2026-04-27 10:34:55
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 22:24:34
'''
# @nc app=nowcoder id=03a5031ed7ad4a7db897fd9ed982ea57 topic=314 question=2368735 lang=Python3
# 2026-04-27 10:34:55
# https://www.nowcoder.com/practice/03a5031ed7ad4a7db897fd9ed982ea57?tpId=314&tqId=2368735
# [NP70] 首都

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    cities_dict = {
        'Beijing': {'Capital': 'China'},
        'Moscow': {'Capital': 'Russia'},
        'Paris': {'Capital': 'France'}
    }
    
    for city in sorted(cities_dict):
        print(f"{city} is the capital of {cities_dict[city]['Capital']}!")

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
