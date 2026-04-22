class Solution:
    def hasSameDigits(self, s: str) -> bool:
        n = len(s)
        while n > 2:
            temp_s = ""
            for i in range(len(s) - 1):
                temp_s += str((int(s[i]) + int(s[i + 1])) % 10)
            s = temp_s
            n = len(s)

        return s[0] == s[1]