class Solution:
    def numSub(self, s: str) -> int:
        # total 用于记录所有仅含 1 的子串的数量, consecutive 记录当前连续 1 的个数
        total, consecutive = 0, 0
        length = len(s)
        for i in range(length):
            if s[i] == '0':
                # 遇到 0 时，将前面一段连续 1 的子串数量累加到 total
                # 连续 n 个 1 的子串数量为 n*(n+1)//2
                total += (consecutive * (consecutive + 1) // 2)
                total %= (10**9+7)
                # 重置连续 1 的计数器
                consecutive = 0
            else:
                # 连续的 1 计数加 1
                consecutive += 1

        # 处理字符串末尾如果是连续的 1 时的情况
        total += consecutive * (consecutive + 1) // 2
        # 结果需要对 10^9+7 取模
        return total % (10 ** 9 + 7)