class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        str = ""
        for i in range(max(len(word1),len(word2))):
            if i < len(word1):
                str += word1[i]
            if i < len(word2):
                str += word2[i]
        return str
    
s = Solution()
print(s.mergeAlternately("abc", "pqr"))