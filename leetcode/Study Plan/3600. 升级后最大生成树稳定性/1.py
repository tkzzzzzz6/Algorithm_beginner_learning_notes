'''
Author: tkzzzzzz6
Date: 2026-03-12 23:51:39
LastEditors: tkzzzzzz6
LastEditTime: 2026-03-12 23:52:01
'''
'''
Author: tkzzzzzz6
Date: 2026-03-12 23:51:39
LastEditors: tkzzzzzz6
LastEditTime: 2026-03-12 23:51:58
'''
'''
Author: tkzzzzzz6
Date: 2026-03-12 23:51:39
LastEditors: tkzzzzzz6
LastEditTime: 2026-03-12 23:51:48
'''
'''
Author: tkzzzzzz6
Date: 2026-03-12 23:51:39
LastEditors: tkzzzzzz6
LastEditTime: 2026-03-12 23:51:41
'''
class UnionFind:
    def __init__(self,n:int):
        self._fa = list(range(n))
        self.cc = n

    def find(self,x:int)->int:
        if self._fa[x] != x:
            self._fa[x] = self.find(self._fa[x])
        return self._fa[x]

    def merge(self,from_:int,to:int)->bool:
        x,y = self.find(from_),self.find(to)
        if x == y:
            return False
        self._fa[x] = y
        self.cc -= 1
        return True
    
class Solution:
    def maxStability(self, n: int, edges: List[List[int]], k: int) -> int:
        must_uf = UnionFind(n)
        all_uf = UnionFind(n)
        min_s,max_s = inf,0
        for x,y,s,must in edges:
            if must and not must_uf.merge(x,y):
                return -1
            all_uf.merge(x,y)
            min_s = min(min_s,s)
            max_s = max(max_s,s)

        if all_uf.cc > 1:
            return -1

        def check(low:int)->bool:
            u = UnionFind(n)
            for x,u,s,must in edges:
                if must and s < low:
                    return False
                if must or s >= low:
                    u.merge(x,y)

            left_k = k
            for x,y,s,must in edges:
                if left_k == 0 or u.cc == 1:
                    break
                if not must and s < low <= s* 2 and u.merge(x,y):
                    left_k -= 1
            return u.cc == 1

        left,right = min_s,max_s*2+1
        while left + 1 < right:
            mid = (left + right) // 2
            if check(mid):
                left = mid
            else:
                right = mid 
        return left
