import sys
import heapq

input = lambda: sys.stdin.readline().rstrip()
INF = 10 ** 18


def main():
    n, m = map(int, input().split())
    s = input().strip()
    L = len(s)

    grid = [input().strip() for _ in range(n)]

    # 方向：0:U, 1:D, 2:L, 3:R
    dir_chars = ['U', 'D', 'L', 'R']
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    # 预处理 nextDelta[p][dir]:
    # 从相位 p (时间 t 满足 t % L == p) 出发，
    # 要等多少秒才能遇到某个方向 dir 的指令（只用“等待 + 跟随指令”，不加手动）
    if L == 0:
        # 理论上不会出现，题目保证 |s| >= 1
        nextDelta = [[INF] * 4]
    else:
        nextDelta = [[INF] * 4 for _ in range(L)]
        s2 = s + s  # 长度 2L

        for d in range(4):
            ch = dir_chars[d]
            # nextPos[i]: 在 s2[i..] 中，下一个等于 ch 的位置下标
            # 没有则为 INF
            last = INF
            nextPos = [INF] * (2 * L)

            # 从右往左扫，维护 last
            for i in range(2 * L - 1, -1, -1):
                if s2[i] == ch:
                    last = i
                nextPos[i] = last

            # 映射回 p ∈ [0, L-1]
            for p in range(L):
                pos = nextPos[p]
                if pos == INF or pos >= p + L:
                    nextDelta[p][d] = INF  # 一整个循环里都没有这个方向
                else:
                    nextDelta[p][d] = pos - p  # 需要等待的秒数（可以为 0）

    # Dijkstra：状态只有 (x, y)，代价是 (manual, time)
    # 我们维护 bestManual[x][y] 和 bestTime[x][y]（x,y 用 0-based 下标）
    bestManual = [[INF] * m for _ in range(n)]
    bestTime = [[INF] * m for _ in range(n)]

    # 起点在 (0,0)，时间 0，手动 0
    bestManual[0][0] = 0
    bestTime[0][0] = 0
    pq = []
    # 堆里放：(manual, time, x, y)
    heapq.heappush(pq, (0, 0, 0, 0))

    while pq:
        man, tim, x, y = heapq.heappop(pq)

        # 判掉过期状态
        if man > bestManual[x][y]:
            continue
        if man == bestManual[x][y] and tim > bestTime[x][y]:
            continue

        # 如果已经弹出的是终点，说明这是字典序最优的 (manual,time)
        if x == n - 1 and y == m - 1:
            print(man, tim)
            return

        # 尝试四个方向
        for d in range(4):
            nx = x + dx[d]
            ny = y + dy[d]
            # 越界 / 墙格子 -> 跳过
            if not (0 <= nx < n and 0 <= ny < m):
                continue
            if grid[nx][ny] == '#':
                continue

            # -------- 1）手动移动这一格 --------
            nman = man + 1
            ntim = tim + 1  # 花 1 秒做手动移动

            # 如果新代价更优，就更新
            if nman < bestManual[nx][ny] or (
                nman == bestManual[nx][ny] and ntim < bestTime[nx][ny]
            ):
                bestManual[nx][ny] = nman
                bestTime[nx][ny] = ntim
                heapq.heappush(pq, (nman, ntim, nx, ny))

            # -------- 2）使用指令串“免费”走这一格 --------
            if L > 0:
                p = tim % L
                delta = nextDelta[p][d]
                if delta != INF:
                    # 等 delta 秒不动，然后在下一秒“跟随指令”走一步
                    nman2 = man          # 手动次数不变
                    ntim2 = tim + delta + 1  # 等 delta 秒 + 走一步

                    if nman2 < bestManual[nx][ny] or (
                        nman2 == bestManual[nx][ny]
                        and ntim2 < bestTime[nx][ny]
                    ):
                        bestManual[nx][ny] = nman2
                        bestTime[nx][ny] = ntim2
                        heapq.heappush(pq, (nman2, ntim2, nx, ny))

    # 理论上题目保证一定可达，这里只是兜底
    print(bestManual[n - 1][m - 1], bestTime[n - 1][m - 1])


if __name__ == "__main__":
    main()
