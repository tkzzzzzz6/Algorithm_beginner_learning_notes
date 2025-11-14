class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        numof1 = 0  # 统计数组中1的个数
        g = 0     # 用于计算整个数组的gcd

        # 遍历所有元素
        for x in nums:
            if x == 1:
                numof1 += 1  # 记录1的数量

            g = gcd(g, x)  # 不断更新gcd

        # 如果数组中本来就有1
        if numof1 > 0:
            return n - numof1  # 只需把其它不是1的数变成1

        # 如果整体gcd大于1，无法全部变为1，返回-1
        if g > 1:
            return -1

        # 没有1且gcd等于1，需要找最短使gcd为1的子数组长度
        min_len = n
        for i in range(n):
            g = 0
            for j in range(i, n):
                g = gcd(g, nums[j])
                if g == 1:  # 找到gcd为1的区间
                    min_len = min(min_len, j - i + 1)
                    break  # 后面越长不会更优，可以跳出

        # 操作数 = 区间内变1的操作数 + 其它变1的操作数
        # 区间内最短为min_len，外部剩下n-1个数，再减去1（因为区间内有两个数变1需要min_len-1步，实际上总步数是min_len+n-2）
        return min_len + n - 2