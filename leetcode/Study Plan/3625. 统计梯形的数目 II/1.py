from collections import defaultdict
from math import inf


class Solution:
    def countTrapezoids(self, points: List[List[int]]) -> int:
        cnt = defaultdict(lambda:defaultdict(int))#斜率->截距->个数
        cnt2 = defaultdict(lambda:defaultdict(int)) #中点->斜率->个数

        for i,(x,y) in enumerate(points):
            for x2,y2 in points[:i]:
                dy = y - y2
                dx = x - x2
                k = dy/dx if dx != 0 else inf
                b = (y*dx - x*dy)/dx if dx != 0 else x
                cnt[k][b] += 1
                cnt2[(x+x2,y+y2)][k] += 1

        ans = 0
        for m in cnt.values():
            s = 0
            for c in m.values():
                ans += c*s
                s += c

        for m in cnt2.values():
            s = 0
            for c in m.values():
                ans -= s*c
                s+=c

        return ans
