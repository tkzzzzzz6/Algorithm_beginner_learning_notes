// 二维前缀和
#include <vector>

using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(),n = grid[0].size();
        int ans = 0;
        vector<vector<int>> sum(m+1,vector<int>(n+1));

        for(int i = 0;i<m;++i){
            for(int j = 0;j<n;++j){
                sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + grid[i][j];
                if(sum[i+1][j+1] >k)break;
                ans+=1;
            }
        }
        return ans;
    }
};
