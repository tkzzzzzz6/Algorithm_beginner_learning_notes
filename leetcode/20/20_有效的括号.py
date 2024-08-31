class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        bracket_map = {")": "(", "}": "{", "]": "["}
        
        for char in s:
            if char in bracket_map:  # 如果是右括号
                if not stack or stack[-1] != bracket_map[char]:
                    return False
                stack.pop()
            else:  # 如果是左括号
                stack.append(char)
        
        return len(stack) == 0  # 栈应该为空，所有左括号都被匹配
    
#leetcode官方解法
class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) % 2 == 1:
            return False
        
        pairs = {
            ")": "(",
            "}": "{",
            "]": "[",
        }   

        stack = list()
        for ch in s:
            if ch in pairs:
                if not stack or stack[-1] != pairs[ch]:
                    return False
                stack.pop()
            else:
                stack.append(ch)

        return not stack