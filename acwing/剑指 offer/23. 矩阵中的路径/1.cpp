/*
#include <vector>
 * @Author: tkzzzzzz6
 * @Date: 2026-04-17 14:53:44
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-17 15:47:56
 */
/*
* @acwing app=acwing.cn id=21 lang=C++
*
* 23. 矩阵中的路径
*/

// @acwing code start

class Solution {
public:
    vector<vector<char>> matrix;
    bool hasPath(vector<vector<char>>& _matrix, string &str) {
        if(_matrix.size() == 0 || _matrix[0].size() == 0 || str.size() == 0)return false;
        matrix = _matrix;
        int n = matrix.size(), m = matrix[0].size();
        for(int x = 0;x<n;++x){
            for(int y = 0;y < m;++y){
                if(dfs(0,x,y,str))
                    return true;
            }
        }
        return false;

    }

    bool dfs(int u,int x,int y,const string &str){
        if(str[u] != matrix[x][y])return false;
        if(u == str.size() - 1)return true;
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        char t = matrix[x][y];
        matrix[x][y] = '#';

        for(int i = 0;i<4;++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < matrix.size() && 0<= ny && ny < matrix[0].size()){
                if(dfs(u+1,nx,ny,str)){
                    matrix[x][y] = t;
                    return true;
                }
            }
        }
        matrix[x][y] = t;
        return false;
    }
};
// @acwing code end
