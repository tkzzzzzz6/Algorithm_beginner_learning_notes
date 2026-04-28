'''
Author: tkzzzzzz6
Date: 2026-04-28 08:56:53
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-28 08:58:05
'''
# @nc app=nowcoder id=c5ab441e5e8f4ec7bf36ba51a3141340 topic=314 question=10059958 lang=Python3
# 2026-04-28 08:56:53
# https://www.nowcoder.com/practice/c5ab441e5e8f4ec7bf36ba51a3141340?tpId=314&tqId=10059958
# [NP98] 修改属性1

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

class Employee:
    def __init__(self,name,salary):
        self.name = name
        self.salary = salary

    def printclass(self):
        try:
            print(f"{self.name}'salary is {self.salary}, and his age is {self.age}")
        except AttributeError:
            print("Error! No age")

def solve():
    name = input()
    salary = int(input())
    age = int(input())
    e = Employee(name,salary)
    e.printclass()
    e.age = age
    e.printclass()

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
