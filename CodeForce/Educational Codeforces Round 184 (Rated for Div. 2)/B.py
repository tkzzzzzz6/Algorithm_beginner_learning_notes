import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    s = input().strip()
    n = len(s)

    # 全是 '*' 的特殊处理
    if '<' not in s and '>' not in s:
        # 若只有一个格子，必然 1；否则有两个相邻 '*' 可以来回 -> 无限
        print(1 if n == 1 else -1)
        continue

    # 若缺少某一方向的流（没有 '<' 或没有 '>'），不能形成往返循环 -> 有限
    # 但上面已经排除了全 '*' 的情况
    if '<' not in s or '>' not in s:
        print(-1)
        continue

    # 否则两种方向都存在，按常规计算
    left_idx = s.find('>')          # 最左侧的 '>' 的索引（0-based）
    right_idx = s.rfind('<')        # 最右侧的 '<' 的索引（0-based）

    ans = min(left_idx, n - 1 - right_idx)
    print(ans)
