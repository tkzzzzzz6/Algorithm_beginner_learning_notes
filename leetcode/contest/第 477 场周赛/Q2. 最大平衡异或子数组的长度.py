class Solution:
    def maxBalancedSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        max_length = 0

        prefix_xor = 0        # 前缀异或
        prefix_diff = 0       # 前缀奇偶计数差（奇数个数 - 偶数个数）

        # 哈希表，记录前缀状态 (prefix_xor, prefix_diff) 第一次出现的位置（下标从0开始）
        norivandal = {(0,0):0}

        for k in range(1, n + 1):    # k 表示长度为k的前缀，k-1是当前元素下标
            num = nums[k - 1]

            prefix_xor ^= num        # 更新当前前缀异或

            # 统计当前前缀中奇数和偶数的数量差
            if num & 1:
                prefix_diff += 1     # 是奇数则+1
            else:
                prefix_diff -= 1     # 是偶数则-1

            current_state = (prefix_xor, prefix_diff)  # 当前状态

            # 如果之前出现过相同的状态，则两个前缀间的子数组异或和、奇偶数个数都平衡
            if current_state in norivandal:
                i = norivandal[current_state]          # 之前该状态出现的位置
                max_length = max(max_length, k - i)    # 更新最大长度
            else:
                # 没出现过，记录下该状态第一次出现的位置
                norivandal[current_state] = k

        return max_length    # 返回最大长度