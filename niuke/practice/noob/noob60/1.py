'''
Author: tkzzzzzz6
Date: 2026-02-06 22:13:56
LastEditors: tkzzzzzz6
LastEditTime: 2026-02-06 22:24:14
'''
import sys

T = int(input())

for _ in range(T):
    A = len(input())
    B = len(input())
    C = len(input())
    D = len(input())

    v = [A,B,C,D]

    mp = {A:'A',B:'B',C:'C',D:'D'}

    v.sort()

    l = min(v)
    r = max(v)

    if v.count(l) == 1 and v.count(r) != 1:
        print(mp[l])
    elif v.count(r) == 1 and v.count(l) != 1:
        print(mp[r])
    else:
        print('C')
