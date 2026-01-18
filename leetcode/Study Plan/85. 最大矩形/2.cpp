// 单调栈
#include<vector>

using namespace std;


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0)
        {
            return 0;
        }
        int n = matrix[0].size();
        vector<vector<int>>left(m,vector<int>(n,0));

        for(int i = 0;i<m;++i)
        {
            for(int j = 0;j<n;++j)
            {
                if(matrix[i][j] == '1')
                {
                    left[i][j] = (j==0?0:left[i][j-1])+1;
                }
            }
        }
        int ret = 0;
        for(int j = 0;j<n;++j)
        {
            vector<int> up(m,0),down(m,0)
        }
    }
};
