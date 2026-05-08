'''
Author: tkzzzzzz6
Date: 2026-04-27 08:47:42
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-27 08:47:46
'''
# @nc app=nowcoder id=feb18b858e1846c7884f802eca8be144 topic=314 question=2366593 lang=Python3
# 2026-04-27 08:47:42
# https://www.nowcoder.com/practice/feb18b858e1846c7884f802eca8be144?tpId=314&tqId=2366593
# [NP49] 字符列表的长度

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    my_list = ['P','y','t','h','o','n']

    print('Here is the original list:')
    print(my_list)
    print()
    print("The number that my_list has is:")
    print(len(my_list))

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
