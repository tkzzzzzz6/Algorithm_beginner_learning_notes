import sys

MAXN = 21
fact = [0] * MAXN
n = 0
bit = []

def update(i, delta):
    while i <= n:
        bit[i] += delta
        i += i & -i

def query(i):
    s = 0
    while i > 0:
        s += bit[i]
        i -= i & -i
    return s

def find_kth(k):
    pos = 0
    current_sum = 0
    log_n = n.bit_length() - 1
    
    for i in range(log_n, -1, -1):
        step = 1 << i
        if pos + step <= n and current_sum + bit[pos + step] < k:
            current_sum += bit[pos + step]
            pos += step
    return pos + 1

def precompute_factorials():
    fact[0] = 1
    for i in range(1, MAXN):
        fact[i] = fact[i - 1] * i

def main():
    global n, bit
    input = sys.stdin.readline
    
    precompute_factorials()
    
    first_line = input().strip()
    if not first_line:
        return
    n_str, q_str = first_line.split()
    n, q = int(n_str), int(q_str)
    
    for _ in range(q):
        type_line = input().strip()
        data_line = input().strip()

        if type_line == 'P':
            k = int(data_line)
            k -= 1

            bit = [0] * (n + 1)
            for i in range(1, n + 1):
                update(i, 1)
            
            p = []
            for i in range(n):
                divisor = fact[n - 1 - i]
                quotient = k // divisor
                k %= divisor
                
                num = find_kth(quotient + 1)
                p.append(num)
                update(num, -1)
            
            print(*p)

        else: # type_line == 'Q'
            p = list(map(int, data_line.split()))
            bit = [0] * (n + 1)
            for i in range(1, n + 1):
                update(i, 1)

            rank = 0
            for i in range(n):
                rank += query(p[i] - 1) * fact[n - 1 - i]
                update(p[i], -1)
            print(rank + 1)

if __name__ == "__main__":
    main()
