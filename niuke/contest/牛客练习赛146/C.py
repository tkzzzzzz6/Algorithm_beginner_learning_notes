import sys, math
from collections import deque, defaultdict, Counter
import heapq, bisect
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n,m = map(int,input().split())
    traps = []
    for _ in range(m):
        t,x = map(int,input().split())
        traps.append((t,x))

    if m == 0:
        T = int(input())
        out = []

        for _ in range(T):
            s = int(input())
            out.append("Yes" if s in traps else "No")
        print("\n".join(out))
        return
    
    # 取出所有陷阱出现的时间
    t_list = [t for t,_ in traps]

    # need[i] 表示在时间点 t_i 必须满足的奇偶要求
    need = [1 - x for _,x in traps]

    s_fixed_min = 0
    s_fixed_max = 0

    L0 = t_list[0]
    alpha = need[0]
    l = alpha
    if L0 <l:
        l = r = 0
    else:
        if(L0 & 1) == (alpha & 1):
            r = L0
        else:
            r = L0 - 1
    s_fixed_min += l
    s_fixed_max += r

    for i in range(m-1):
        L = t_list[i+1] - t_list[i]
        alpha = need[i] ^ need[i+1]
        l = alpha
        if L < l:
            l = r = 0
        else:       
            if(L&1) == (alpha & 1):
                r = L
            else:
                r = L - 1
        s_fixed_min += l
        s_fixed_max += r

    L_last = n - t_list[-1]

    Tq = int(input())
    out = []

    if L_last > 0:
        L_total = s_fixed_min
        R_total = s_fixed_max + L_last
        for _ in range(Tq):
            s = int(input())
            if L_total <= s <= R_total:
                out.append("Yes")
            else:
                out.append("No")
        
    else:
        L_total = s_fixed_min
        R_total = s_fixed_max
        parity = s_fixed_min & 1
        for _ in range(Tq):
            s = int(input())
            if L_total <= s <= R_total and (s &  1)== parity:
                out.append("Yes")
            else:
                out.append("No")

    print("\n".join(out))



if __name__ == "__main__":
    sys.setrecursionlimit(10**7)
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


