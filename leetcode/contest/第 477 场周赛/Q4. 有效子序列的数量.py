from typing import List

class Solution:
    def countEffective(self, nums: List[int]) -> int:
        MOD = 10**9 + 7
        n = len(nums)
        
        # 总 OR
        tot = 0
        for x in nums:
            tot |= x
        
        # 如果总 OR 为 0，说明全是 0，不可能让 OR 更小
        if tot == 0:
            return 0
        
        # 提取 tot 中为 1 的 bit，压缩
        bits = []
        for i in range(20):  # 因为 nums[i] <= 1e6 < 2^20
            if (tot >> i) & 1:
                bits.append(i)
        
        B = len(bits)
        allmask = (1 << B) - 1
        
        # 统计每种压缩 bitmask 的出现次数
        size = 1 << B
        cnt = [0] * size
        
        for x in nums:
            mask = 0
            for j, b in enumerate(bits):
                if (x >> b) & 1:
                    mask |= (1 << j)
            cnt[mask] += 1
        
        # SOS DP：F[s] = sum_{sub ⊆ s} cnt[sub]
        F = cnt[:]  # 拷贝一份
        for i in range(B):
            bit = 1 << i
            for mask in range(size):
                if mask & bit:
                    F[mask] += F[mask ^ bit]
        
        # 预处理 2^k
        max_k = n  # sum_no_intersect(t) ≤ n
        pow2 = [1] * (max_k + 1)
        for i in range(1, max_k + 1):
            pow2[i] = (pow2[i - 1] * 2) % MOD
        
        # 容斥求 |E1 ∪ E2 ∪ ...|
        ans = 0
        for t in range(1, size):
            comp = allmask ^ t
            sum_no = F[comp]   # 与 t 完全不相交的元素个数
            ways = pow2[sum_no]
            
            if bin(t).count("1") % 2 == 1:
                ans = (ans + ways) % MOD
            else:
                ans = (ans - ways) % MOD
        
        return ans % MOD
