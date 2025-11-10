class Solution:
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        grid = [[0] * n for  _ in range(m)]   # 网格状态数组
        q = deque([])   # 广度优先搜索队列
        # 每个方向的单位向量
        dx = [1, 0, -1, 0]
        dy = [0, 1, 0, -1]
        
        # 标记警卫的位置，并将每个警卫四个方向的初始视线入队
        for i, j in guards:
            grid[i][j] = -1  # -1 代表这个格子是警卫
            for k in range(4):
                # (i, j, k) 表示从(i, j)出发向第k个方向(0-3)发射视线
                q.append((i, j, k))
        
        # 标记墙的位置
        for i, j in walls:
            grid[i][j] = -2  # -2 代表这个格子是墙
        
        # BFS 遍历所有视线
        while q:
            x, y, k = q.popleft()
            nx, ny = x + dx[k], y + dy[k]
            if 0 <= nx < m and 0 <= ny < n and grid[nx][ny] >= 0:
                # 如果当前方向k还没覆盖过(nx, ny)这个格子
                if (grid[nx][ny] & (1 << k)) == 0:
                    # 用位运算标记：第k方向已被该视线覆盖
                    grid[nx][ny] |= (1 << k)
                    # 将下一个视线状态入队，继续往前推进
                    q.append((nx, ny, k))
        
        # 统计未被任何视线、警卫或墙覆盖的格子的数量
        res = 0
        for i in range(m):
            for j in range(n):
                # 如果该格子既不是警卫(-1)、也不是墙(-2)，且也未被任何方向的视线覆盖(值==0)
                if grid[i][j] == 0:
                    res += 1
        return res
