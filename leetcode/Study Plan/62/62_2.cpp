//采用杨辉三角的方法，时间复杂度O(n^2)，空间复杂度O(n^2)
//虽然时间复杂度高,但是可以将范围内的所有组合数都计算出来,对于需要频繁计算组合数的问题
//可以使用这种方法
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<uint32_t>> C(n+m,vector<uint32_t>(n+m));
        for (int i = 0;i<n+m;i++){
            for (int j = 0;j<=i;j++){
                if (j == 0 || j==i) C[i][j]=1;
                else C[i][j] C[i-1][j-1]+C[i-1][j];
            }
        }
        return C[n+m-2][n-1];
    }
};