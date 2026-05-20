'''
Author: tkzzzzzz6
Date: 2026-05-12 18:50:18
LastEditors: tkzzzzzz6
LastEditTime: 2026-05-12 19:06:15
'''
# Nowcoder Compiler: Python3

import sys

data = iter(map(int,sys.stdin.buffer.read().split()))

n = next(data)
q = next(data)

prefix = [0]*(n+1)
for i in range(1,n+1):
    prefix[i] = prefix[i-1] + next(data)

ans = []
for _ in range(q):
    l = next(data)
    r = next(data)

    ans.append(str(prefix[r] - prefix[l-1]));

sys.stdout.write("\n".join(ans))
