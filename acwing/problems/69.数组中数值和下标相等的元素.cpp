/*
 * @acwing app=acwing.cn id=65 lang=C++
 *
 * 69. 数组中数值和下标相等的元素
 */

// @acwing code start

class Solution {
   public:
    int getNumberSameAsIndex(vector<int> &nums) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] < mid)
                l = mid + 1;
            else
                r = mid;
        }

        if (nums[l] != l)
            return -1;

        return nums[l];
    }
};
// @acwing code end
