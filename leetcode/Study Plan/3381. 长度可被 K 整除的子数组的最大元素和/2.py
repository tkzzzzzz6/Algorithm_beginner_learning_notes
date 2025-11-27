class Solution:
    def maxSubarraySum(self, nums: List[int], k: int) -> int:
        # 初始化每种余数下的最小前缀和数组，初值为正无穷大
        min_s = [inf]*k
        # 特殊处理，让初始余数为 -1（实际对应 k-1）的位置为0，代表前缀和起点
        min_s[-1] = s = 0
        ans = -inf  # 初始化最大和为负无穷
        for j, x in enumerate(nums):
            s += x  # 累加当前元素到前缀和
            i = j % k  # 当前下标对k取模，代表子数组长度模k的类型
            # 以当前位置结尾、长度可被k整除的子数组最大和
            ans = max(ans, s - min_s[i])
            # 更新当前模k类型下最小前缀和
            min_s[i] = min(min_s[i], s)
        return ans
