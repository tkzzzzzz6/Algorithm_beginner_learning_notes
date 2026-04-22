/*
#include <vector>
 * @Author: tkzzzzzz6
 * @Date: 2026-03-22 18:32:49
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-03-22 18:32:54
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       int n = matrix.size();
        // 转置
        for(int i = 0;i<n;++i){
            for(int j = 0;j<i;++j){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        // 行翻转
        for(auto &row:matrix)
            ranges::reverse(row);
    }
};
