from collections import deque
class Solution:
    def findLexSmallestString(self, s: str, a: int, b: int) -> str:
        
        n = len(s)
        visited = set()
        queue = deque([s])
        visited.add(s)
        result = s
        
        while queue:
            curr = queue.popleft()
            
            # 更新最小字典序
            if curr < result:
                result = curr
            
            # 操作1：累加（对奇数位+a）
            add_result = self.addOperation(curr, a)
            if add_result not in visited:
                visited.add(add_result)
                queue.append(add_result)
            
            # 操作2：轮转（向右轮转b位）
            rotate_result = self.rotateOperation(curr, b)
            if rotate_result not in visited:
                visited.add(rotate_result)
                queue.append(rotate_result)
        
        return result
    
    def addOperation(self, s: str, a: int) -> str:
        """对所有奇数位置加a（模10）"""
        result = list(s)
        for i in range(1, len(s), 2):  # 奇数位：1, 3, 5, ...
            digit = int(result[i])
            result[i] = str((digit + a) % 10)
        return ''.join(result)
    
    def rotateOperation(self, s: str, b: int) -> str:
        """向右轮转b位"""
        n = len(s)
        b = b % n  # 处理b > n的情况
        return s[-b:] + s[:-b]