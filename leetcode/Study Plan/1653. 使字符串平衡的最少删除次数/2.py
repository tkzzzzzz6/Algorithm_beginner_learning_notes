class Solution:
    def minimumDeletions(self, s: str) -> int:
        f = cnt_b = 0
        for c in s:
            if c == 'b':
                cnt_b += 1
            else:
                f = min(f + 1,cnt_b)
        return f
