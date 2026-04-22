/*
#include <vector>
 * @Author: tkzzzzzz6
 * @Date: 2026-04-14 08:24:21
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-14 08:24:26
 */
/*
* @acwing app=acwing.cn id=15 lang=C++
*
* 14. 不修改数组找出重复的数字
*/

// @acwing code start

class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        int n = nums.size()-1;
        for(auto x:nums){
            if(x > n || x < 1)return -1;
        }
        vector<int> hash(nums.size(),0);
        for(auto x:nums){
            if(hash[x] != 0){
                return x;
            }
            hash[x] += 1;
        }
        return -1;
    }
};
// @acwing code end
