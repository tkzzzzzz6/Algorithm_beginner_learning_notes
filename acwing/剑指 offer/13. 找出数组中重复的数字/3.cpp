#include <vector>
#include <algorithm>
/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-13 10:45:59
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-13 11:02:24
 */
class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)return -1;
        sort(nums.begin(),nums.end());
        if(nums[0] < 0 || nums[n-1] >= n)return -1;
        for(int i = 1;i<n;++i){
            if(nums[i-1] == nums[i])return nums[i];
        }
        return -1;
    }
};
