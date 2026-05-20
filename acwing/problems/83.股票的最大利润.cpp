/*
 * @acwing app=acwing.cn id=79 lang=C++
 *
 * 83. 股票的最大利润
 */

// @acwing code start

class Solution {
   public:
    int maxDiff(vector<int> &nums) {
        if (nums.size() == 0) // 特判数组为空
            return 0;
        int minn = nums[0]; // 存储最小值
        int maxx = 0;       // 存储结果
        for (int i = 1; i < nums.size(); ++i) {
            maxx = max(maxx, nums[i] - minn);
            minn = min(nums[i], minn);
        }

        return maxx;
    }
};
// @acwing code end
