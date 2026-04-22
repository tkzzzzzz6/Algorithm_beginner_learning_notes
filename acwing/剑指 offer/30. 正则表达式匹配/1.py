'''
Author: tkzzzzzz6
Date: 2026-04-20 11:16:10
LastEditors: tkzzzzzz6
LastEditTime: 2026-04-20 11:24:14
'''
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        @cache
        def dfs(i:int,j:int)->bool:
            if j == len(p):
                return i == len(s)

            is_match = i < len(s) and (p[j] == '.' or p[j] == s[i])

            # 匹配零个或多个
            if j + 1 < len(p) and p[j+1] == '*':
                return (dfs(i,j+2) or is_match and dfs(i+1,j))

            # s[i] 和 p[j]相匹配
            return is_match and dfs(i+1,j+1)

        return dfs(0,0)
