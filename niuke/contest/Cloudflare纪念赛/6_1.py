import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    n = int(input())
    s = input().strip()

    L = s.count('L')
    R = s.count('R')
    U = s.count('U')
    D = s.count('D')

    # 1. 只有水平运动
    if U + D == 0:
        ans = max(L, R) + 1

    # 2. 只有竖直运动
    elif L + R == 0:
        ans = max(U, D) + 1

    # 3. 横纵都有
    else:
        total = L + R + U + D
        hori_balanced = (L > 0 and R > 0 and L == R)
        vert_balanced = (U > 0 and D > 0 and U == D)

        if hori_balanced and vert_balanced:
            ans = total     # 必有重复，最多 n 个点
        else:
            ans = total + 1 # 可以构造简单路径，访问 n+1 个点

    print(ans)
