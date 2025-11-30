class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        # 计算前缀和数组，s[i] 表示 nums[0] 到 nums[i-1] 的和
        # initial=0 表示前缀和数组的第一个元素为 0
        s = list(accumulate(nums,initial = 0))
        
        # x 表示整个数组和模 p 的余数
        # 如果我们需要删除一个子数组使得剩余和能被 p 整除
        # 那么被删除的子数组的和模 p 的余数必须等于 x
        x = s[-1] % p
        
        # 如果整个数组和已经能被 p 整除，不需要删除任何元素
        if x == 0:
            return 0
        
        # ans 记录最短子数组长度，初始化为数组长度
        # n 为数组长度
        ans = n  = len(nums)
        
        # last 字典记录每个前缀和模 p 的余数最后出现的位置
        last = {}
        
        # 遍历前缀和数组
        for i,v in enumerate(s):
            # 记录当前前缀和模 p 的余数对应的位置
            last[v%p] = i
            
            # 如果我们要删除子数组 nums[j+1...i-1]
            # 那么删除后的和为 s[n] - (s[i] - s[j]) = s[n] - s[i] + s[j]
            # 要使这个和能被 p 整除，需要 (s[n] - s[i] + s[j]) % p == 0
            # 即 (x - v + s[j]) % p == 0，也就是 s[j] % p == (v - x) % p
            # 查找是否存在满足条件的前缀和位置 j
            j = last.get((v-x)%p,-n)
            
            # 如果找到了满足条件的位置 j，更新最短长度
            # 子数组长度为 i - j（因为删除的是 nums[j+1...i-1]）
            ans = min(ans,i-j)

        # 如果找到了有效的子数组（ans < n），返回长度；否则返回 -1
        return ans if ans < n else -1
