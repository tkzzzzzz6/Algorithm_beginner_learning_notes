import bisect  # 导入二分查找模块，用于快速查找有序数组中的插入位置

class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        """
        题意：给定数组 nums，可以进行最多 numOperations 次操作
        每次操作可以将任意元素 +k 或 -k
        求操作后，数组中出现频率最高的数字的频率
        
        思路：
        1. 先统计原数组中每个数字的出现次数
        2. 枚举每个可能的目标值，计算有多少数字可以通过操作变成它
        3. 对于目标值 i，范围 [i-k, i+k] 内的数字都可以变成 i
        """
        
        # 第一步：排序数组，便于后续二分查找和统计
        nums.sort()
        
        # ans: 记录最终答案（最大频率）
        ans = 0
        
        # num_count: 字典，key=数字，value=该数字在原数组中出现的次数
        # 例如：nums=[1,1,2,2,2,3] → num_count={1:2, 2:3, 3:1}
        num_count = {}
        
        # last_num_index: 记录当前正在统计的数字的起始索引位置
        last_num_index = 0
        
        #  统计原数组中每个数字的出现次数 
        for i in range(len(nums)):
            # 如果当前数字与上一个不同数字不同（遇到了新的数字）
            if nums[i] != nums[last_num_index]:
                # 将上一个数字及其出现次数存入字典
                # 出现次数 = 当前索引 - 起始索引
                num_count[nums[last_num_index]] = i - last_num_index
                
                # 更新答案：原数组中已有的最大频率
                ans = max(ans, i - last_num_index)
                
                # 更新起始索引为当前位置，开始统计新的数字
                last_num_index = i
        
        # 循环结束后，处理最后一个数字（因为循环里只处理了"不同"的情况）
        num_count[nums[last_num_index]] = len(nums) - last_num_index
        ans = max(ans, len(nums) - last_num_index)
        
        #  枚举所有可能的目标值 
        # 从最小值到最大值，枚举每个可能成为目标的数字
        # 为什么是这个范围？因为操作只能 +k 或 -k，超出这个范围的目标值不可能有数字能变成它
        for i in range(nums[0], nums[-1] + 1):
            
            #  使用二分查找找到 [i-k, i+k] 范围内的数字 
            
            # bisect_left: 找到第一个 >= (i-k) 的元素位置
            # l 是范围左边界的索引
            l = bisect.bisect_left(nums, i - k)
            
            # bisect_right: 找到第一个 > (i+k) 的元素位置
            # r 是范围右边界的索引（减1是因为 bisect_right 返回的是"大于"的位置）
            r = bisect.bisect_right(nums, i + k) - 1
            
            # 区间 [l, r] 内的所有数字都可以通过一次操作变成 i
            # 因为它们与 i 的差距都 <= k
            
            #  计算选择 i 作为目标值时的最大频率 
            
            if i in num_count:
                # 情况1：i 本身在原数组中存在
                
                # num_count[i]: i 原本就有的数量（不需要操作）
                # r - l + 1: 区间内总共有多少个数字
                # numOperations: 最多可以操作多少次
                
                # 策略：优先保留原有的 i，然后对区间内其他数字进行操作
                # 最多操作次数不能超过 numOperations
                # 总数量不能超过区间内的总数量
                temp_ans = min(r - l + 1, num_count[i] + numOperations)
                
                # 解释：
                # - 如果 num_count[i] + numOperations >= r-l+1，说明操作次数足够，可以把区间内所有数字都变成 i
                # - 否则，只能变成 num_count[i] + numOperations 个
                
            else:
                # 情况2：i 本身在原数组中不存在
                
                # 没有原本的 i，所以需要从 0 开始操作
                # 最多操作 numOperations 次
                # 但也不能超过区间内的总数量
                temp_ans = min(r - l + 1, numOperations)
                
                # 解释：
                # - 如果 numOperations >= r-l+1，可以把区间内所有数字都变成 i
                # - 否则，只能变成 numOperations 个
            
            # 更新全局最优答案
            ans = max(ans, temp_ans)
        
        # 返回最大频率
        return ans