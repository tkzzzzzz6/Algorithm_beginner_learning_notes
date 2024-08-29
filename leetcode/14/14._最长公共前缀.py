#纵向扫描方法
from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
    
        # 取第一个字符串作为初始公共前缀
        for i in range(len(strs[0])):
            char = strs[0][i]  # 当前字符
            for j in range(1, len(strs)):
                # 如果当前字符超出当前字符串长度或不匹配
                if i == len(strs[j]) or strs[j][i] != char:
                    return strs[0][:i]  # 返回公共前缀
        
        return strs[0]  # 所有字符串都相同