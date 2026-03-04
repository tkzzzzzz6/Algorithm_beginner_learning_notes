class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        ans = 0
        for row in mat:
            col = -1
            for i,x in enumerate(row):
                if x == 0:
                    continue
                if col >= 0:
                    col = -1
                    break
                col = i
            if col < 0:
                continue

            see1 = 0
            for r in mat:
                if r[col] == 0:
                    continue
                see1 += 1
                if see1 > 1:
                    see1 = 0
                    break

            ans += see1

        return ans
            
