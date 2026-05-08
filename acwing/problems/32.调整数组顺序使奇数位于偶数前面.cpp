#include <vector>
/*
* @acwing app=acwing.cn id=30 lang=C++
*
* 32. 调整数组顺序使奇数位于偶数前面
*/

// @acwing code start

class Solution {
public:
    void reOrderArray(vector<int> &array) {
         int l = 0,r = array.size() - 1;
         while(l<=r){
            if(l <= r && array[l] % 2 == 1)++l;
            if(l <= r && array[r] % 2 == 0)--r;
            if(l < r) swap(array[l],array[r]);
         }
    }
};
// @acwing code end
