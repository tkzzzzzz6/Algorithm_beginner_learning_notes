class Solution:
    def longestBalanced(self, nums: List[int]) -> int:
        n = len(nums)
        max_len = 0

        for i in range(n):
            even_set = set()  
            odd_set = set()   
            
            # 枚举所有可能的终点
            for j in range(i, n):
                # 将当前元素加入对应的集合
                if nums[j] % 2 == 0:
                    even_set.add(nums[j])
                else:
                    odd_set.add(nums[j])
                
                # 检查是否平衡
                if len(even_set) == len(odd_set):
                    max_len = max(max_len, j - i + 1)
        
        return max_len