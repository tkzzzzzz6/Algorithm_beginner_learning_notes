'''
Author: tkzzzzzz6
Date: 2026-09-29 13:25:53
LastEditors: tkzzzzzz6
LastEditTime: 2026-09-29 15:17:50
'''
import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()


MOD = 998244353

def solve():
    data = sys.stdin.read().split()
    index = 0
    L = int(data[index]);index += 1
    K = int(data[index]); index += 1
    N = int(data[index]); index += 1

    # 读取位置约束
    constraints = []
    for _ in range(K):
        p = int(data[index]); index += 1
        c = data[index]; index += 1
        constraints.append((p, c))
    # 按位置排序
    constraints.sort()

    # 读入禁止串
    forbidden = []
    for _ in range(N):
        forbidden.append(data[index]); index += 1

    # 建 Trie
    nxt = [[-1] * 26]  # nxt[node][c] = child node index or -1
    fail = [0]          # fail 指针
    is_end = [False]    
    for s in forbidden:
        node = 0
        for ch in s:
            c = ord(ch) - ord('a')
            if nxt[node][c] == -1:
                nxt[node][c] = len(nxt)
                nxt.append([-1] * 26)
                fail.append(0)
                is_end.append(False)
            node = nxt[node][c]
        is_end[node] = True

    # BFS 求 fail 指针 + 补全 go 表
    q = deque()
    # 根的所有孩子，fail 指向根；根的缺边全部自环到根
    for c in range(26):
        v = nxt[0][c]
        if v != -1:
            fail[v] = 0
            q.append(v)
        else:
            nxt[0][c] = 0  # 根的缺边自环，方便后面 go 表的查询

    while q:
        u = q.popleft()
        for c in range(26):
            v = nxt[u][c]
            if v == -1:
                # u 在字符 c 上没有真实孩子，补全 go 表：走 fail[u] 的 go 转移
                # 因为 fail[u] 已经被处理过，nxt[fail[u]][c] 一定不是 -1
                nxt[u][c] = nxt[fail[u]][c]
                continue

            # v 是 u 的真实孩子，求 fail[v]
            f = fail[u]
            # 兜底循环（正常情况下 nxt[fail[u]][c] 一定存在）
            while f != 0 and nxt[f][c] == -1:
                f = fail[f]
            fail_candidate = nxt[f][c]

            # 只有候选不等于自己时才用它，否则指向根
            if fail_candidate != v:
                fail[v] = fail_candidate
            else:
                fail[v] = 0

            # 递归向上传播终点标记（不止看 fail[v] 一层）
            f2 = fail[v]
            while f2 != 0 and not is_end[f2]:
                f2 = fail[f2]
            if is_end[f2]:
                is_end[v] = True

            q.append(v)

    # 现在 nxt[u][c] 就是 "在 u 读入 c 跳到哪个节点"，并且0 号节点一定安全
    S = len(nxt)
    #标记非法节点
    illegal = [is_end[i] for i in range(S)]

    # 构造转移矩阵 M（状态数 S）
    # M[u][v] = 有多少字符 c 使得 nxt[u][c] == v 且 v 合法
    M = [[0] * S for _ in range(S)]
    for u in range(S):
        if illegal[u]:
            continue
        for c in range(26):
            v = nxt[u][c]
            if not illegal[v]:
                M[u][v] = (M[u][v] + 1) % MOD

    # 矩阵快速幂预处理 M^(2^i)
    def mat_mul(A, B):
        n = len(A)
        C = [[0] * n for _ in range(n)]
        for i in range(n):
            Ai = A[i]
            Ci = C[i]
            for k in range(n):
                if Ai[k] == 0:
                    continue
                aik = Ai[k]
                Bk = B[k]
                for j in range(n):
                    if Bk[j]:
                        Ci[j] = (Ci[j] + aik * Bk[j]) % MOD
        return C

    # 计算最大需要的幂次（log2(L) 大约 60）
    max_pow = L.bit_length()
    powers = [M]
    for i in range(1, max_pow):
        powers.append(mat_mul(powers[-1], powers[-1]))

    # 向量 × 矩阵 快速幂：V = V * M^d
    def vec_pow(V, d):
        # V 是长度为 S 的列表
        res = [0] * S
        for i in range(len(res)):
            res[i] = V[i]
        bit = 0
        while d:
            if d & 1:
                # res = res * powers[bit]
                new_res = [0] * S
                for i in range(S):
                    if res[i] == 0:
                        continue
                    ri = res[i]
                    Pi = powers[bit][i]
                    for j in range(S):
                        if Pi[j]:
                            new_res[j] = (new_res[j] + ri * Pi[j]) % MOD
                res = new_res
            d >>= 1
            bit += 1
        return res

    # 强制一步：只在状态 u 上读入字符 c 跳到 nxt[u][c]
    def force_step(V, c):
        new = [0] * S
        c = ord(c) - ord('a')
        for u in range(S):
            if V[u] == 0:
                continue
            v = nxt[u][c]
            if not illegal[v]:
                new[v] = (new[v] + V[u]) % MOD
        return new

    # 初始状态：只有一个空串，状态在根
    V = [0] * S
    V[0] = 1

    prev = 0
    for (p, c) in constraints:
        d = p - prev - 1
        if d > 0:
            V = vec_pow(V, d)
        V = force_step(V, c)
        prev = p

    #末尾段
    d = L - prev
    if d > 0:
        V = vec_pow(V, d)

    # 求和
    ans = sum(V) % MOD
    print(ans)


if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()
