class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        # 存储结果（出现两次的数字）
        res = []
        # 使用字典记录每个数字出现的次数
        count = {}
        
        # 遍历数组中的每个数字
        for x in nums:
            # 更新数字x的出现次数（如果不存在则初始化为0，然后加1）
            count[x] = count.get(x, 0) + 1
            # 当某个数字第二次出现时，将其加入结果列表
            if count[x] == 2:
                res.append(x)
        
        # 返回所有出现两次的数字
        return res

