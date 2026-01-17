from typing import List


class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        res = 0
        for i in range(1, len(points)):
            p = points[i - 1]
            q = points[i]
            res += max(abs(p[0] - q[0]), abs(p[1] - q[1]))  # 切比雪夫距离
        return res
