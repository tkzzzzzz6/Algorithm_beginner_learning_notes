class Solution:
    def hasSameDigits(self, s: str) -> bool:
        n = len(s)      
        
        # 将字符串转换为列表，方便修改
        # 例如: "1234" -> ['1', '2', '3', '4']
        s_list = list(s)
        
        # 外层循环：控制压缩的轮数
        # 第1轮: n-1个元素 (压缩掉1个)
        # 第2轮: n-2个元素 (压缩掉2个)
        # ...
        # 第n-2轮: 2个元素 (最终剩2个)
        for i in range(1, n - 1):
            # 内层循环：在当前轮中，处理相邻的数字对
            # 第i轮需要处理 n-i 对相邻数字
            for j in range(n - i):

                # chr() 将ASCII码转回字符
                s_list[j] = chr((int(s_list[j]) + int(s_list[j+1])) % 10)
        
        # 经过 n-2 轮压缩后，只剩下2个数字
        # 判断这两个数字是否相同
        return s_list[0] == s_list[1]

