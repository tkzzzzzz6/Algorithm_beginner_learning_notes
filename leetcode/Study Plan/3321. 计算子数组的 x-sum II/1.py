"""
【题目】计算子数组的 x-sum II

【问题描述】
给定数组 nums，窗口大小 k，参数 x。需要计算每个大小为 k 的滑动窗口的 x-sum。

【x-sum 定义】
1. 统计窗口内每个数字的出现频率
2. 选出频率最高的前 x 个数字（频率相同时选数值大的）
3. x-sum = 这些数字的 (频率 × 数值) 之和

【核心思路】动态维护"频率前 x 名"
使用两个有序集合来高效维护窗口内频率最高的前 x 个元素：

【关键操作】
1. 插入元素：
   - 如果元素已存在，先删除旧的 (旧频率, 数值) 对
   - 更新频率 +1，插入新的 (新频率, 数值) 对
   - 判断是否进入 VIP 区：VIP 区未满 或 比 VIP 区最弱的强
   - 如果 VIP 区超过 x 个，将最弱的踢到候补区

2. 删除元素：
   - 找到并删除当前的 (频率, 数值) 对
   - 更新频率 -1
   - 如果频率还>0，重新插入新的 (新频率, 数值) 对
   - 如果删除的是 VIP 区元素，从候补区提拔最强的补上

3. 排序规则 (频率, 数值)：
   - 优先比较频率：频率高的排前面
   - 频率相同时比较数值：数值大的排前面
   - 例如：(3,5) > (2,10)，(3,10) > (3,5)

【滑动窗口流程】
for 每个位置 i:
    1. insert(nums[i])        # 窗口右边界扩展
    2. remove(nums[i-k])      # 窗口左边界收缩
    3. get()                  # 获取当前 VIP 区的加权和

【时间复杂度】O(n log n)
- 每次 insert/remove：O(log n) （有序集合操作）
- n 个窗口：O(n log n)

【示例】
nums = [1,1,2,2,3], k=3, x=2

窗口 [1,1,2]: 频率 {1:2次, 2:1次}
  VIP区: (2,1), (1,2) → x-sum = 2×1 + 1×2 = 4

窗口 [1,2,2]: 频率 {1:1次, 2:2次}
  VIP区: (2,2), (1,1) → x-sum = 2×2 + 1×1 = 5

窗口 [2,2,3]: 频率 {2:2次, 3:1次}
  VIP区: (2,2), (1,3) → x-sum = 2×2 + 1×3 = 7

返回: [4, 5, 7]
"""

from collections import defaultdict
from sortedcontainers import SortedList

class tools:
    def __init__(self, x):
        self.x = x                           # number of highest frequency elements to keep
        self.result = 0                      # current weighted sum of chosen elements
        self.large = SortedList()            # elements in top-x set (ordered by (freq, value))
        self.small = SortedList()            # remaining elements
        self.cnt = defaultdict(int)          # frequency map for numbers

    def insert(self, num):
        if self.cnt[num] > 0:                # remove old pair before updating frequency
            self.internal_remove((self.cnt[num], num))
        self.cnt[num] += 1
        self.internal_insert((self.cnt[num], num))

    def remove(self, num):
        self.internal_remove((self.cnt[num], num))
        self.cnt[num] -= 1
        if self.cnt[num] > 0:                # reinsert if still present
            self.internal_insert((self.cnt[num], num))

    def get(self):
        return self.result

    def internal_insert(self, p):
        if len(self.large) < self.x or p > self.large[0]:
            self.result += p[0] * p[1]       # add contribution to sum
            self.large.add(p)
            if len(self.large) > self.x:     # rebalance when exceeding x
                to_remove = self.large[0]
                self.result -= to_remove[0] * to_remove[1]
                self.large.remove(to_remove)
                self.small.add(to_remove)
        else:
            self.small.add(p)

    def internal_remove(self, p):
        if p >= self.large[0]:               # removal from top-x set
            self.result -= p[0] * p[1]
            self.large.remove(p)
            if self.small:                   # promote best candidate from small
                to_add = self.small[-1]
                self.result += to_add[0] * to_add[1]
                self.small.remove(to_add)
                self.large.add(to_add)
        else:
            self.small.remove(p)

class Solution:
    def findXSum(self, nums, k, x):
        helper = tools(x)
        ans = []

        for i in range(len(nums)):
            helper.insert(nums[i])           # insert current window element
            if i >= k:
                helper.remove(nums[i - k])   # remove element leaving window
            if i >= k - 1:
                ans.append(helper.get())     # record sum for current window

        return ans
