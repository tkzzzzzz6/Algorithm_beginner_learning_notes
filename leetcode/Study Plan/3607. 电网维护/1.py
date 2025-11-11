from typing import List, Dict

class DSU:
    def __init__(self, size: int) -> None:
        # parent[i] 表示节点 i 在并查集中的父节点
        self.parent = list(range(size))

    def find(self, x: int) -> int:
        # 路径压缩查找根节点
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def join(self, u: int, v: int) -> None:
        # 将两个节点所在的集合合并
        self.parent[self.find(v)] = self.find(u)


class Solution:
    def processQueries(
        self,
        c: int,
        connections: List[List[int]],
        queries: List[List[int]],
    ) -> List[int]:
        dsu = DSU(c + 1)
        # 先把所有已有连接并入并查集中
        for u, v in connections:
            dsu.join(u, v)

        # online[i] 记录站点 i 当前是否在线
        online = [True] * (c + 1)
        # offline_counts[i] 记录站点 i 被下线的次数（用于逆序处理时判断是否仍需保持离线）
        offline_counts = [0] * (c + 1)
        # minimum_online_stations[root] 记录根节点为 root 的联通块中编号最小的在线站点
        minimum_online_stations: Dict[int, int] = {}

        # 正向遍历查询，先统计每个站点被下线的次数并标记初始离线状态
        for op, x in queries:
            if op == 2:
                online[x] = False
                offline_counts[x] += 1

        # 初始化每个联通块的最小在线站点
        for i in range(1, c + 1):
            root = dsu.find(i)
            if root not in minimum_online_stations:
                minimum_online_stations[root] = -1
            # 如果站点在线且更小，则更新联通块的最小在线站点
            if online[i]:
                if minimum_online_stations[root] == -1 or minimum_online_stations[root] > i:
                    minimum_online_stations[root] = i

        ans: List[int] = []
        # 逆序处理查询以模拟撤销离线操作（离线 -> 回滚为上线）
        for op, x in reversed(queries):
            root = dsu.find(x)
            station = minimum_online_stations[root]

            if op == 1:
                # 查询操作：若站点在线直接返回，否则返回所在联通块的最小在线站点
                ans.append(x if online[x] else station)
            else:
                # 恢复操作：若还有未撤销的离线记录则仅递减计数，否则标记为上线并更新最小在线站点
                if offline_counts[x] > 1:
                    offline_counts[x] -= 1
                else:
                    online[x] = True
                    if station == -1 or station > x:
                        minimum_online_stations[root] = x

        # 结果逆序还原为原始查询顺序
        return ans[::-1]
