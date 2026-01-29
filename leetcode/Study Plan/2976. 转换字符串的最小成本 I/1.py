'''
Author: tkzzzzzz6
Date: 2026-01-29 21:25:41
LastEditors: tkzzzzzz6
LastEditTime: 2026-01-29 21:25:48
'''
class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        dis = [[inf]*26 for _ in range(26)]
        for i in range(26):
            dis[i][i] = 0

        for x,y,c in zip(original,changed,cost):
            x = ord(x) - ord('a')
            y = ord(y) - ord('a')
            dis[x][y] = min(dis[x][y],c)

        for k in range(26):
            for i in range(26):
                if dis[i][k] == inf:
                    continue
                for j in range(26):
                    dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j])

        ans = sum(dis[ord(x)-ord('a')][ord(y) - ord('a')] for x,y in zip(source,target))
        return ans if ans < inf else -1
