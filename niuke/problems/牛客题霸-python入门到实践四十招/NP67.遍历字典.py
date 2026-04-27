'''
Author: tkzzzzzz6
Date: 2026-04-27 09:48:07
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 09:54:25
'''
# @nc app=nowcoder id=0315639767824323a2cdb9ee3f998314 topic=314 question=2368391 lang=Python3
# 2026-04-27 09:48:07
# https://www.nowcoder.com/practice/0315639767824323a2cdb9ee3f998314?tpId=314&tqId=2368391
# [NP67] 遍历字典

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    operators_dict = {
        '<': 'less than',
        '==': 'equal'
    }

    print('Here is the original dict:')

    for op in sorted(operators_dict):
        print(f'Operator {op} means {operators_dict[op]}.')

    operators_dict['>'] = 'greater than'

    print()
    print('The dict was changed to:')

    for op in sorted(operators_dict):
        print(f'Operator {op} means {operators_dict[op]}.')
    

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
