'''
Author: tkzzzzzz6
Date: 2026-04-22 22:03:37
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-22 22:09:17
'''
# @nc app=nowcoder id=66969869634b4142ac371684fcf89764 topic=314 question=2365325 lang=Python3
# 2026-04-22 22:03:37
# https://www.nowcoder.com/practice/66969869634b4142ac371684fcf89764?tpId=314&tqId=2365325
# [NP16] 发送offer

# @nc code=start

import sys, math
import string
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def printSentence1(name:string):
    print(f"{name}, you have passed our interview and will soon become a member of our company.")

def printSentence2(name:string):
    print(f"{name}, welcome to join us!")


def solve():
    offer_list = ["Allen","Tom"]
    for name in offer_list:
        printSentence1(name)

    offer_list[1] = "Andy"
    for name in offer_list:
        printSentence2(name)



if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()



# @nc code=end
