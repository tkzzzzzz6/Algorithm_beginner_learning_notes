'''
Author: tkzzzzzz6
Date: 2026-04-28 09:05:06
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-28 09:13:24
'''
# @nc app=nowcoder id=7831806be5684ad6ac0f8b43e3e3558e topic=314 question=10059984 lang=Python3
# 2026-04-28 09:05:06
# https://www.nowcoder.com/practice/7831806be5684ad6ac0f8b43e3e3558e?tpId=314&tqId=10059984
# [NP99] 修改属性2

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
        print(f"{self.name}'salary is {self.salary}, and his age is {self.age}")

def solve():
    name = input()
    salary = int(input())
    age = int(input())

    e = Employee(name,salary)

    hasage = hasattr(e,'age')
    print(hasage)
    if not hasage:
        e.__setattr__('age',age)
    e.printclass()
    

if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
