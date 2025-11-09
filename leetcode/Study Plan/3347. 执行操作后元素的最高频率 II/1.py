class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        # 排序数组，便于后续二分查找和统计连续相同元素
        nums.sort()
        
        # 记录最终答案：某个值能达到的最大出现频率
        ans = 0
        
        # 统计原数组中每个数字的出现次数
        num_count = defaultdict(int)
        
        # 候选模式集合：存储所有可能成为高频目标值的数字
        modes = set()
        
        def add_mode(value):
            """
            将value及其相关候选值加入modes集合
            
            思路：如果要让某个数字出现次数最多，有三种可能的目标值：
            1. value本身
            2. value - k：范围内的其他数可以通过 +k 操作变成 value
            3. value + k：范围内的其他数可以通过 -k 操作变成 value
            """
            modes.add(value)
            # 只有当 value-k 在数组范围内时才加入
            if value - k >= nums[0]:
                modes.add(value - k)
            # 只有当 value+k 在数组范围内时才加入
            if value + k <= nums[-1]:
                modes.add(value + k)
        
        # 记录当前处理的相同数字的起始位置
        last_num_index = 0
        
        # 第一次遍历：统计每个不同数字的出现次数
        for i in range(len(nums)):
            # 当遇到不同的数字时
            if nums[i] != nums[last_num_index]:
                # 记录前一个数字的出现次数（从last_num_index到i-1）
                num_count[nums[last_num_index]] = i - last_num_index
                # 更新答案（不操作时的最大频率）
                ans = max(ans, i - last_num_index)
                # 将该数字及其相关候选值加入modes
                add_mode(nums[last_num_index])
                # 更新起始位置为当前位置
                last_num_index = i
        
        # 处理最后一组相同的数字
        num_count[nums[last_num_index]] = len(nums) - last_num_index
        ans = max(ans, len(nums) - last_num_index)
        add_mode(nums[last_num_index])
        
        # 第二次遍历：对每个候选模式计算能达到的最大频率
        for mode in sorted(modes):
            # 使用二分查找找到 [mode-k, mode+k] 范围内的所有元素
            # l: 第一个 >= mode-k 的元素位置
            l = bisect.bisect_left(nums, mode - k)
            # r: 最后一个 <= mode+k 的元素位置
            r = bisect.bisect_right(nums, mode + k) - 1
            
            # 计算以mode为目标值时能达到的最大频率
            if mode in num_count:
                # 情况1：mode原本就存在于数组中
                # 最大频率 = min(范围内总元素数, 原有数量 + 允许操作次数)
                temp_ans = min(r - l + 1, num_count[mode] + numOperations)
            else:
                # 情况2：mode不在原数组中
                # 最大频率 = min(范围内总元素数, 允许操作次数)
                # 因为每个变成mode的元素都需要一次操作
                temp_ans = min(r - l + 1, numOperations)
            
            # 更新全局最大值
            ans = max(ans, temp_ans)
        
        return ans