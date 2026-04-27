'''
Author: tkzzzzzz6
Date: 2026-04-27 09:55:05
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 09:55:09
'''
# @nc app=nowcoder id=c3ceb05574634213af021104a63aa14b topic=314 question=2368555 lang=Python3
# 2026-04-27 09:55:05
# https://www.nowcoder.com/practice/c3ceb05574634213af021104a63aa14b?tpId=314&tqId=2368555
# [NP68] 毕业生就业调查

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    survey_list = ['Niumei','Niu Ke Le','GURR','LOLO']
    result_dict = {
        'Niumei': 'Nowcoder',
        'GURR': 'HUAWEI'
    }

    for s in survey_list:
        if s in result_dict.keys():
            print(f'Hi, {s}! Thank you for participating in our graduation survey!')
        else:
            print(f'Hi, {s}! Could you take part in our graduation survey?')



if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
