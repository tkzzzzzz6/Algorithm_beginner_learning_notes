class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        total = sum(nums)  # 计算数组总和
        left_sum = 0  # 左侧元素和
        
        for i in range(len(nums)):
            right_sum = total - left_sum - nums[i]  # 右侧元素和
            if left_sum == right_sum:  # 如果左右和相等，找到中心索引
                return i
            left_sum += nums[i]  # 更新左侧和
        
        return -1  # 没找到中心索引
