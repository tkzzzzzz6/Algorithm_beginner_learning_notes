// 使用柱状图的优化暴力方法
#include <vector>

using namespace std;
class Solution {
   public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        int m = matrix.size();
        if(m == 0){
            return 0;
        }
        int n = matrix[0].size();
        vector<vector<int>>left(m,vector<int>(n,0));

        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(matrix[i][j] == '1')
                {
                    left[i][j] = (j == 0?1:left[i][j-1]+1);
                }
            }
        }
        int ret = 0;
        for(int i = 0;i<m;++i)
        {
            for(int j = 0;j<n;++j)
            {
                if(matrix[i][j] == '0')
                {
                    continue;
                }
                int width = left[i][j];
                int area = width;
                for(int k = i - 1;k>=0;--k)
                {
                    width = min(width,left[k][j]);
                    area = max(area,(i-k+1)*width);
                }
                ret = max(ret,area);
            }
        }
        return ret;
    }
};
