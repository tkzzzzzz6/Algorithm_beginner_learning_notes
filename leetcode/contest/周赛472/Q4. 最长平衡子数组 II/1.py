class Solution:
    def longestBalanced(self, nums: List[int]) -> int:
        n = len(nums)
        
        # 从最长可能的长度开始枚举
        for length in range(n, 0, -1):
            # 枚举所有长度为length的子数组
            for i in range(n - length + 1):
                even_set = set()
                odd_set = set()
                
                # 统计子数组[i, i+length-1]
                for j in range(i, i + length):
                    if nums[j] % 2 == 0:
                        even_set.add(nums[j])
                    else:
                        odd_set.add(nums[j])
                
                # 找到平衡子数组，立即返回
                if len(even_set) == len(odd_set):
                    return length
        
        