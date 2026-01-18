class Solution:
    def largestMagicSquare(self, grid: List[List[int]]) -> int:
        m,n = len(grid),len(grid[0])
        
        row_sum = [[0]*(n+1) for _ in range(m)] #向右前缀和
        col_sum = [[0]*(n+1) for _ in range(m+1)] #向下前缀和
        diag_sum = [[0]*(n+1) for _ in range(m+1)] #主对角线前缀和
        anti_sum = [[0]*(n+1) for _ in range(m+1)] #反对角线前缀和
        
        for i,row in enumerate(grid):
            for j,x in enumerate(row):
                row_sum[i][j+1] = row_sum[i][j] + x
                col_sum[i+1][j] = col_sum[i][j] + x 
                diag_sum[i+1][j+1] = diag_sum[i][j] + x
                anti_sum[i+1][j] = anti_sum[i][j+1] + x
        
        # k*k子矩阵的左上角为(i-k,j-k),右下角为(i-1,j-1)
        for k in range(min(m,n),0,-1):
            for i in range(k,m+1):
                for j in range(k,n+1):
                    # 子矩阵主对角线和
                    s = diag_sum[i][j] - diag_sum[i-k][j-k]
                    
                    # 子矩阵反对角线和
                    # 子矩阵每行和每列的和都是 s
                    if anti_sum[i][j-k] - anti_sum[i-k][j] == s and \
                        all(row_sum[r][j] - row_sum[r][j-k] == s for r in range(i-k,i)) and \
                        all(col_sum[i][c] - col_sum[i-k][c] == s for c in range(j-k,j)):
                            return k