/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-12 13:35:46
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-12 13:48:47
 */
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result;
    int n = nums.size();
    sort(nums.begin(), nums.end()); // 排序

    for (int i = 0; i < n; ++i) {
      if (nums[i] > 0)
        continue;

      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      int left = i + 1, right = n - 1;
      while (left < right) {
        long long s = nums[i] + nums[left] + nums[right];
        if (s > 0)
          right--;
        else if (s < 0)
          left++;
        else {
          result.push_back(
              {nums[i], nums[left], nums[right]}); // 存储数值而不是索引
          while (left < right && nums[left] == nums[left + 1]) { // 添加边界检查
            left++;
          }
          while (left < right &&
                 nums[right] == nums[right - 1]) { // 添加边界检查
            right--; // 应该是 right--，不是 right++
          }
          left++;  // 继续向右移动
          right--; // 继续向左移动
        }
      }
    }
    return result;
  }
};
