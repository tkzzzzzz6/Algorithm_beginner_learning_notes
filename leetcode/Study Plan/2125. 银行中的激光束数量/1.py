class Solution:
    def numberOfBeams(self,bank:List[str])->int:
        last = ans = 0
        for line in bank:
            cnt = line.count('1') # 统计每一行安全设备的个数
            if cnt != 0:
                ans += last * cnt
                last = cnt #将前面不为0的一行的安全设备的数量进行记录
        return ans