/*
#include <vector>
 * @Author: tkzzzzzz6
 * @Date: 2026-04-13 10:45:59
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-13 10:48:48
 */
class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        int n = nums.size();
        for(auto x:nums){
            if(x >= n || x < 0)return -1;
        }
        for(int i = 0;i<n;++i){
            while(nums[i] != nums[nums[i]])swap(nums[i],nums[nums[i]]);
            if(nums[i] != i)return nums[i];

        }
        return -1;
    }
};
