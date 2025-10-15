#纵向扫描法_1
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
    
#纵向扫描法_2
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
    
        if not strs:
            return ""
        
        # 取第一个字符串作为初始公共前缀
        prefix,count = strs[0],len(strs)

        for i in range(1,count):
            prefix = self.lcp(prefix,strs[i])
            if not prefix:
                break
        return prefix
    
    def lcp(self,str1,str2):
        length,index = min(len(str1),len(str2)),0
        while index < length and str1[index] == str2[index]:
            index += 1

        return str1[:index]        


#横向扫描法_1
from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
    
        if not strs:
            return ""
        
        prefix = strs[0]  # 取第一个字符串作为初始公共前缀
        for i in range(1, len(strs)):
            prefix = self.lcp(prefix, strs[i])  # 求当前字符串与当前公共前缀的最长公共前缀
            if not prefix:  # 如果当前公共前缀为空
                break
        
        return prefix
    
    def lcp(self, str1: str, str2: str) -> str:
        length, index = min(len(str1), len(str2)), 0
        while index < length and str1[index] == str2[index]:
            index += 1
        return str1[:index]  # 返回最长公共前缀
    
#纵向扫描法_2
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:

        if not strs:
            return ""
        
        length,count = len(strs[0]),len(strs)

        for i in range(length):
            char = strs[0][i]   
            if any(i == len(strs[j]) or strs[j][i] != char for j in range(1,count)):
                return strs[0][:i]
        
        return strs[0]

    
#分治法
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        def lcp(start,end):
            if start == end:
                return strs[start]
            
            mid = (start + end) // 2
            left_lcp,right_lcp = lcp(start,mid),lcp(mid+1,end)
            min_len = min(len(left_lcp),len(right_lcp))
            for i in range(min_len):
                if left_lcp[i] != right_lcp[i]:
                    return left_lcp[:i]
            
            return left_lcp[:min_len]
        
        return "" if not strs else lcp(0,len(strs)-1)
    
#二分查找法
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:

        def isCommonPrefix(length):
            str0,count = strs[0][:length],len(strs)
            return all(strs[i][:length] == str0 for i in range(1,count))
        
        if not strs:
            return ""
        
        min_len = min(len(s) for s in strs)
        low,high = 0,min_len
        while low < high:
            mid = (high - low + 1)//2 + low
            if isCommonPrefix(mid):
                low = mid
            else:
                high = mid - 1

        return strs[0][:low]