class Solution:
    # 如果字符串 colors 中有若干相邻的重复颜色，则这些颜色中最多只能保留一个。
    # 因此，我们可以采取贪心的策略：在这一系列重复颜色中，我们保留删除成本最高的颜色，并删除其他颜色。
    # 这样得到的删除成本一定是最低的。

    def minCost(self, colors: str, neededTime: List[int]) -> int:
        i = 0
        n = len(colors)
        res = 0

        while i < n:
            ch = colors[i]
            maxValue = 0
            total = 0

            while i < n and colors[i] == ch:
                maxValue = max(maxValue, neededTime[i]) # 删除成本最高的颜色，这里的成本指的是序号的长度
                total += neededTime[i]
                i += 1
            
            res += total - maxValue
        
        return res
