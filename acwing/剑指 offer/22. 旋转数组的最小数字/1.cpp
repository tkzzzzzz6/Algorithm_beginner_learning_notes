/*
* @acwing app=acwing.cn id=20 lang=C++
*
* 22. 旋转数组的最小数字
*/

// @acwing code start

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)return -1;
        while(n > 0 && nums[0] == nums[n-1])n--;
        if(nums[n-1] >= nums[0])return nums[0];
        int l = 0,r = n -1;
        while(l < r){
            int mid = l + r >> 1;
            if(nums[0] <= nums[mid]) l = mid + 1;
            else r = mid;
        }
        return nums[l];
    }
};
// @acwing code end
