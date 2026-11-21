import sys, math

def solve():
    data = sys.stdin.buffer.read().split()
    idx = 0
    T = int(data[idx]); idx += 1
    out = []
    
    for _ in range(T):
        n = int(data[idx]); idx += 1
        L = float('-inf')
        R = float('inf')
        ok = True
        
        for _ in range(n):
            a = int(data[idx]); idx += 1
            b = int(data[idx]); idx += 1
            c = int(data[idx]); idx += 1
            
            if not ok:
                continue
            
            delta = b * b - 4 * a * c
            if delta < 0:
                ok = False
                continue
            
            sq = math.sqrt(delta)
            # a < 0：x1 是较大根，x2 是较小根
            x1 = (-b - sq) / (2 * a)
            x2 = (-b + sq) / (2 * a)
            
            left  = math.ceil(x2 + 1e-12)
            right = math.floor(x1 - 1e-12)
            
            if left > right:
                ok = False
                continue
            
            if left > L:  L = left
            if right < R: R = right
        
        out.append("YES" if (ok and L <= R) else "NO")
    
    sys.stdout.write('\n'.join(out) + '\n')

solve()
