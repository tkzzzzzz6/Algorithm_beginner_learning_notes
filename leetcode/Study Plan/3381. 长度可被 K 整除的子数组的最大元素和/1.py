class Solution:
    def maxSubarraySum(self, nums: List[int], k: int) -> int:
        # 计算前缀和数组，pre[i] 表示 nums 的前 i 个元素之和，初始加上 0 方便处理前缀和
        pre = list(accumulate(nums, initial=0))
        # 记录每种余数下对应的最小前缀和，初值为无穷大
        min_s = [inf] * k
        ans = -inf  # 初始化答案为负无穷
        for j, s in enumerate(pre):
            i = j % k  # 当前前缀和的下标对 k 取模，代表这一类余数
            # 更新答案，s - min_s[i] 表示以当前位置结尾的、长度可被 k 整除的子数组最大和
            ans = max(ans, s - min_s[i])
            # 维护每个余数对应的最小前缀和
            min_s[i] = min(min_s[i], s)
        return ans
