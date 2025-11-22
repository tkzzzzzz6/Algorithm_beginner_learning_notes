class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        n = len(s)
        res = 0
        # 枚举两侧字符
        for i in range(26):
            l, r = 0, n - 1
            # 寻找该字符第一次出现的下标
            while l < n and ord(s[l]) - ord('a') != i:
                l += 1
            # 寻找该字符最后一次出现的下标
            while r >= 0 and ord(s[r]) - ord('a') != i:
                r -= 1
            if r - l < 2:
                # 该字符未出现，或两下标中间的子串不存在
                continue
            # 利用哈希集合统计 s[l+1..r-1] 子串的字符总数，并更新答案
            charset = set()
            for k in range(l + 1, r):
                charset.add(s[k])
            res += len(charset)
        return res

