/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-30 13:01:06
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-30 13:26:55
 */
/*
 * @acwing app=acwing.cn id=63 lang=C++
 *
 * 67. 数字在排序数组中出现的次数
 */

// @acwing code start

class Solution {
   public:
    int getNumberOfK(vector<int> &nums, int k) {
        if (nums.empty())
            return 0;

        int l = 0, r = nums.size();
        // 找第一个 k 的位置
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] < k)
                l = mid + 1;
            else
                r = mid;
        }
        if (nums[l] != k)
            return 0;

        // 找第一个大于 k 的数的位置
        int left = l;
        r = nums.size(); // nums[l] == k,l的值可以不修改
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] <= k)
                l = mid + 1;
            else
                r = mid;
        }

        return l - left;
    }
};
// @acwing code end
