#include <vector>
/*
* @acwing app=acwing.cn id=16 lang=C++
*
* 15. 二维数组中的查找
*/

// @acwing code start

class Solution {
public:
    bool searchArray(vector<vector<int>> array, int target) {
        if(array.empty() || array[0].empty())return false;
        int i = 0,j = array[0].size() - 1;
        while(i < array.size()  && j >= 0){
            if(array[i][j] == target)return true;
            if(array[i][j] > target)j--;
            else i++;
        }
        return false;
    }
};
// @acwing code end
