'''
Author: tkzzzzzz6
Date: 2026-10-04 12:26:35
LastEditors: tkzzzzzz6
LastEditTime: 2026-10-04 13:43:53
'''
# Nowcoder Compiler: Python3
import sys,math
from dataclasses import dataclass

@dataclass
class Team:
    name:str
    p:int
    t:int

    def __lt__(self,other:"Team")->bool:
        if self.p != other.p:
            return self.p > other.p
        return self.t < other.t



def solve():
    data = sys.stdin.read().split()
    if not data:
        return 
    
    iterator =iter(data)

    n = int(next(iterator))

    team46 = []
    name46 = set()

    lzr46 = None
    for _ in range(n):
        name = next(iterator)
        p = int(next(iterator))
        t = int(next(iterator))

        team = Team(name,p,t)
        team46.append(team)
        name46.add(name)

        if name == "lzr010506":
            lzr46 = team
    
    
    m = int(next(iterator))
    team47 = []
    name47 = set()

    lzr47 = None
    for _ in range(m):
        name = next(iterator)
        p = int(next(iterator))
        t = int(next(iterator))

        team = Team(name,p,t)
        team47.append(team)
        name47.add(name)

        if name == "lzr010506":
            lzr47 = team


    rank46 = 1
    for t in team46:
        if t.name == "lzr010506":
            continue

        if t < lzr46 and t.name not in name47:
            rank46 += 1

        
    rank47 = 1
    for t in team47:
        if t.name == 'lzr010506':
            continue

        if t < lzr47 and t.name not in name46:
            rank47 += 1

    print(min(rank47,rank46))


if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    solve()
