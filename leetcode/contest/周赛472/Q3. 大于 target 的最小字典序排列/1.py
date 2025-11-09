class Solution:
    def lexGreaterPermutation(self, s: str, target: str) -> str:
        from collections import Counter
        
        n = len(s)
        count = Counter(s)  # 统计s中每个字符的可用次数（用于回溯时恢复状态）
        
        def dfs(i:int, greater:bool):
            
            if i == n:
                return "" if greater else None
            
            if greater:
                result = []
                for c in sorted(count.keys()):  # 按字母顺序遍历
                    result.extend([c] * count[c])  # 将该字符重复count[c]次
                return ''.join(result)
            
            for c in sorted(count.keys()):
                if count[c] == 0:
                    continue
                
                if c < target[i]:
                    continue
                
                new_greater = (c > target[i])
                
                count[c] -= 1
                
                rest = dfs(i + 1, greater or new_greater)
                
                count[c] += 1
                
                if rest is not None:
                    return c + rest

            return None
        
        result = dfs(0, False)
        
        return result if result else ""