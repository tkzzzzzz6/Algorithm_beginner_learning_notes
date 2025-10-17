import sys

def main():
    sys.setrecursionlimit(1 << 25)
    
    def input():
        return sys.stdin.read()

    data = input().strip().split()
    n = int(data[0])
    m = int(data[1])
    k = int(data[2])
    seed = int(data[3])

    class RNG:
        def __init__(self, seed):
            self.seed = seed

        def rnd(self):
            ret = self.seed
            self.seed = (self.seed ^ ((self.seed << 13) & 0xFFFFFFFF)) & 0xFFFFFFFF
            self.seed = (self.seed ^ ((self.seed >> 17) & 0xFFFFFFFF)) & 0xFFFFFFFF
            self.seed = (self.seed ^ ((self.seed << 5) & 0xFFFFFFFF)) & 0xFFFFFFFF
            return ret

    rng = RNG(seed)

    # 使用字典存储操作，减少空间复杂度
    row_ops = {}  # {row_index: (time, value)}
    col_ops = {}  # {col_index: (time, value)}

    # 记录最后一次操作的时间
    last_time = 0

    # 记录所有操作
    for t in range(1, k + 1):
        r = rng.rnd()
        op = (r % 2) + 1
        if op == 1:
            r_i = (rng.rnd() % n) + 1
            x = (rng.rnd() % (n * m)) + 1
            row_ops[r_i] = (t, x)
        else:
            c_j = (rng.rnd() % m) + 1
            b = (rng.rnd() % (n * m)) + 1
            col_ops[c_j] = (t, b)
        last_time = t

    total = 0
    
    # 预处理列操作的总和
    col_sum = 0
    latest_cols = 0  # 记录有多少列有操作
    for c in col_ops.values():
        col_sum += c[1]
        latest_cols += 1

    # 对每一行计算贡献
    for r in range(1, n + 1):
        if r not in row_ops:
            # 如果这一行没有行操作，直接用列和计算
            total += r * col_sum
        else:
            row_time, row_val = row_ops[r]
            # 计算被列操作覆盖的部分
            for c, (col_time, col_val) in col_ops.items():
                if col_time > row_time:
                    total += r * col_val
            # 计算未被覆盖的部分
            remaining_cells = m - sum(1 for _, (t, _) in col_ops.items() if t > row_time)
            total += r * row_val * remaining_cells

    print(total)

if __name__ == "__main__":
    main()