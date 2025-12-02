class Solution:
    def countTrapezoids(self, points: List[List[int]]) -> int:
        mod = 10**9+7
        cnt = Counter(y for _,y in points)
        ans = 0
        s = 0
        for y in cnt.values():
            c = y*(y-1)//2
            ans += c*s
            s += c
        return ans%mod
