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
            
            # ������С�ֵ���
            if curr < result:
                result = curr
            
            # ����1���ۼӣ�������λ+a��
            add_result = self.addOperation(curr, a)
            if add_result not in visited:
                visited.add(add_result)
                queue.append(add_result)
            
            # ����2����ת��������תbλ��
            rotate_result = self.rotateOperation(curr, b)
            if rotate_result not in visited:
                visited.add(rotate_result)
                queue.append(rotate_result)
        
        return result
    
    def addOperation(self, s: str, a: int) -> str:
        """����������λ�ü�a��ģ10��"""
        result = list(s)
        for i in range(1, len(s), 2):  # ����λ��1, 3, 5, ...
            digit = int(result[i])
            result[i] = str((digit + a) % 10)
        return ''.join(result)
    
    def rotateOperation(self, s: str, b: int) -> str:
        """������תbλ"""
        n = len(s)
        b = b % n  # ����b > n�����
        return s[-b:] + s[:-b]