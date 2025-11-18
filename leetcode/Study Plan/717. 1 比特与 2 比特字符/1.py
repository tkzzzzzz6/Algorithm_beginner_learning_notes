class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        i ,n = 0,len(bits)
        while i < n-1:
            i += bits[i] + 1 #跳过bits[i]为1的情况
        return i == n-1