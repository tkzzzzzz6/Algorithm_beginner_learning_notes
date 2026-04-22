/*
* @acwing app=acwing.cn id=39 lang=C++
*
* 40. 顺时针打印矩阵
*/

// @acwing code start

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        if(matrix.empty() || matrix[0].empty())return vector<int>();
        
        vector<int> res;
        int n = matrix.size(),m = matrix[0].size();
        int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};

        int d = 0,x = 0,y = 0;
        vector<vector<bool>> vis(n,vector<bool>(m));

        for(int k = 0;k<n*m;++k){
            res.push_back(matrix[x][y]);
            vis[x][y] = true;

            int a = x + dx[d];
            int b = y + dy[d];

            if(a<0 || a >= n || b < 0 || b >= m || vis[a][b]){
                d = (d+1) %4;
                a = x+dx[d],b = y + dy[d];
            }
            x = a,y = b;
        }
        return res;
    }
};
// @acwing code end
