from collections import defaultdict
from math import inf
from collections import Counter


class Solution:
    def countTrapezoids(self, points: List[List[int]]) -> int:
        groups = defaultdict(list)
        group2 = defaultdict(list)

        for i,(x,y) in enumerate(points):
            for x2,y2 in points[:i]:
                dy = y - y2
                dx = x - x2
                k = dy/dx if dx != 0 else inf
                b = (y*dx - x*dy)/dx if dx != 0 else x
                groups[k].append(b)
                group2[(x+x2,y+y2)].append(k)


        ans = 0
        for g in groups.values():
            if len(g) == 1:
                continue
            s = 0
            for c in Counter(g).values():
                ans += c*s
                s += c

        for g in group2.values():
            if len(g) == 1:
                continue
            s = 0
            for c in Counter(g).values():
                ans -= s*c
                s += c

        return ans
