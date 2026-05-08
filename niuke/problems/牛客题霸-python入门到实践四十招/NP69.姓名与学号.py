'''
Author: tkzzzzzz6
Date: 2026-04-27 10:00:17
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 10:33:22
'''
# @nc app=nowcoder id=ab68195587de46c59e2d327a4942d345 topic=314 question=2368629 lang=Python3
# 2026-04-27 10:00:17
# https://www.nowcoder.com/practice/ab68195587de46c59e2d327a4942d345?tpId=314&tqId=2368629
# [NP69] 姓名与学号

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    my_dict_1 = {'name': 'Niuniu','Student ID': 1}
    my_dict_2 = {'name': 'Niumei','Student ID': 2}
    my_dict_3 = {'name': 'Niu Ke Le','Student ID': 3}

    dict_list = []

    dict_list.append(my_dict_1)
    dict_list.append(my_dict_2)
    dict_list.append(my_dict_3)

    for x in dict_list:
        print(f"{x['name']}'s student id is {x['Student ID']}.")

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
