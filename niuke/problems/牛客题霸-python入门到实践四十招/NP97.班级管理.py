'''
Author: tkzzzzzz6
Date: 2026-04-28 08:40:45
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-28 08:55:42
'''
# @nc app=nowcoder id=e5539db11767449ab2fb68ed3c2446d0 topic=314 question=2584238 lang=Python3
# 2026-04-28 08:40:45
# https://www.nowcoder.com/practice/e5539db11767449ab2fb68ed3c2446d0?tpId=314&tqId=2584238
# [NP97] 班级管理

# @nc code=start

import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

class Student:
    def __init__(self,name,id,score:int,home_work_grade:list):
        self.name = name
        self.id = id
        self.score = score
        self.home_work_grade = home_work_grade

    def __str__(self):
        count = len(self.home_work_grade)
        home_work_garde_str = ' '.join(self.home_work_grade)

        return f"{self.name}'s student number is {self.id}, and his grade is {self.score}. He submitted {count} assignments, each with a grade of {home_work_garde_str}"

    # def print_info(self):
    #     count = len(self.home_work_grade)
    #     home_work_garde_str = ' '.join(self.home_work_grade)

    #     print(f"{self.name}'s student number is {self.id}, and his grade is {self.score}. He submitted {count} assignments, each with a grade of {home_work_garde_str}")


def solve():
    name = input()
    id = input()
    score = int(input())
    home_work_grade = input().split()

    stu1 = Student(name,id,score,home_work_grade)

    # stu1.print_info();
    print(stu1)
    
if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


# @nc code=end
