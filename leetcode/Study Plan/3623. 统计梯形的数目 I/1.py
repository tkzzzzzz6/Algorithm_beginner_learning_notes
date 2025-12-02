class Solution:
    def countTrapezoids(self, points: List[List[int]]) -> int:
        # 记录每个 y 坐标出现的点数
        point_num = defaultdict(int)
        mod = 10**9+7
        # ans 用于记录最终答案，total_sum 记录之前所有边的组合数
        ans, total_sum = 0, 0
        # 统计每个 y 坐标对应的点的数量
        for point in points:
            point_num[point[1]] += 1
        # 遍历每个 y 坐标对应的点数
        for p_num in point_num.values():
            # 在同一 y 坐标上可以选出多少条边
            edge = p_num * (p_num - 1) // 2
            # 当前所有边和之前已经统计过的边可以形成的梯形数目
            ans = (ans + edge * total_sum) % mod
            # 累加当前的边数到 total_sum，供后续使用
            total_sum = (total_sum + edge) % mod

        return ans
