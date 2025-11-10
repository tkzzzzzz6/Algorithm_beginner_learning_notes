class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        # 递归终止条件：如果n已经为0，不需要任何操作
        if n == 0:
            return 0
        # 找到n的最高位1对应的位数（x），例如n=8，x=3（因为1000的最高1在第3位，从0开始计数）
        x = len(bin(n)) - 3  # bin(n)形如'0b100...'，减去'0b'和第一个'1'前面的位数
        # 利用格雷码及其反演性质，递推公式：
        # (1<<(x+1))-1 表示全1（共x+1位）的数，减去递归剩余部分的答案
        return (1 << (x + 1)) - 1 - self.minimumOneBitOperations(n - (1 << x))