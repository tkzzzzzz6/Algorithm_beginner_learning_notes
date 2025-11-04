class Solution:
    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        n = len(nums)  # 数组长度
        if n < k:
            return []  # 如果长度不足k无法构成有效窗口，直接返回空列表
        res = [0] * (n - k + 1)  # 结果列表，记录每个长度为k的子数组的x-sum
        cnt = dict()  # 用于记录当前窗口内每个数字出现的次数

        for i in range(n):
            t = nums[i]  # 当前遍历到的元素

            # 更新窗口内元素出现次数
            if t in cnt:
                cnt[t] += 1
            else:
                cnt[t] = 1

            # 窗口滑动，移除窗口左边界的元素一次
            if i >= k:
                cnt[nums[i - k]] -= 1
                if cnt[nums[i - k]] == 0:
                    del cnt[nums[i - k]]  # 若该元素次数减为0，彻底删除

            # 当前窗口内已有k个元素，开始计算x-sum
            if i >= k - 1:
                if len(cnt) <= x:
                    # 如果窗口内不同元素不超过x，直接求所有元素的sum
                    res[i - k + 1] = sum(t * cnt[t] for t in cnt)
                else:
                    # 若窗口内有多于x种元素，选择出现次数最多的x种
                    # 出现次数优先，次数相同按数字本身降序
                    arr = sorted(cnt.items(), key = lambda t: (-t[1], -t[0]))
                    res[i - k + 1] = sum(t * y for t, y in arr[:x])
        return res