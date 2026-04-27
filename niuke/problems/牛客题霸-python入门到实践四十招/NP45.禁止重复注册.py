'''
Author: tkzzzzzz6
Date: 2026-04-27 08:18:37
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 08:30:06
'''
# @nc app=nowcoder id=43acd439112c4b85a9168ad3dd7e2bd1 topic=314 question=2368198 lang=Python3
# 2026-04-27 08:18:37
# https://www.nowcoder.com/practice/43acd439112c4b85a9168ad3dd7e2bd1?tpId=314&tqId=2368198
# [NP45] 禁止重复注册

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    current_users = ['Niuniu','Niumei','GURR','LOLO']
    current_users_lower = [x.lower() for x in current_users]

    new_users = ['GurR','Niu Ke Le','LoLo','Tuo Rui Chi']

    for u in new_users:
        if u.lower() in current_users_lower:
            print('The user name {} has already been registered! Please change it and try again!'.format(u))
        else:
            print('Congratulations, the user name {} is available!'.format(u))

    


if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
