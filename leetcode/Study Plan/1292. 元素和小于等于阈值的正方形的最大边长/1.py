""" 
ABC
DEF
GHI
"""

"""  
要得到
EF
HI
可以先减去左边条ADG,在减去上边条ABC,再加上A(减了两次)
"""
class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        m,n = len(mat),len(mat[0])
        s = [[0]*(n+1) for _ in range(m+1)]
        for i,row in enumerate(mat):
            for j,x in enumerate(row):
                s[i+1][j+1] = s[i+1][j] +s[i][j+1] - s[i][j] + x

        #返回左上角在(r1,c1),右下角在(r2,c2)的子矩阵元素和
        def query(r1:int,c1:int,r2:int,c2:int)->int:
            return s[r2+1][c2+1]-s[r2+1][c1] - s[r1][c2+1]+s[r1][c1]

        ans = 0
        for i in range(m):
            for j in range(n):
                #边长为ans+1的正方形,左上角在(i,j),右下角在(i+ans,j+ans)
                while i + ans < m and j + ans < n and query(i,j,i+ans,j+ans) <= threshold:
                    ans += 1
        return ans
