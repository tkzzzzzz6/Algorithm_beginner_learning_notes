/*
#include <vector>
 * @Author: tkzzzzzz6
 * @Date: 2026-04-12 14:05:03
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-12 14:22:05
 */
class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> result;
    int n = nums.size();
    if (n < 4)
      return {};

    sort(nums.begin(), nums.end());

    for (int k = 0; k <= n - 4; ++k) {
      if (k > 0 && nums[k] == nums[k - 1])
        continue;

      long long min1 =
          (long long)nums[k] + nums[k + 1] + nums[k + 2] + nums[k + 3];
      if (min1 > target)
        break;
      long long max1 =
          (long long)nums[k] + nums[n - 1] + nums[n - 2] + nums[n - 3];
      if (max1 < target)
        continue;

      for (int i = k + 1; i <= n - 3; ++i) {
        if (i > k + 1 && nums[i] == nums[i - 1])
          continue;

        long long min2 =
            (long long)nums[k] + nums[i] + nums[i + 1] + nums[i + 2];
        if (min2 > target)
          break;
        long long max2 =
            (long long)nums[k] + nums[i] + nums[n - 1] + nums[n - 2];
        if (max2 < target)
          continue;

        int left = i + 1, right = n - 1;
        while (left < right) {
          long long s = (long long)nums[k] + nums[i] + nums[left] + nums[right];
          if (s > target)
            right--;
          else if (s < target)
            left++;
          else {
            result.push_back({nums[k], nums[i], nums[left], nums[right]});
            while (left < right && nums[left] == nums[left + 1])
              left++;
            while (left < right && nums[right] == nums[right - 1])
              right--;
            left++;
            right--;
          }
        }
      }
    }
    return result;
  }
};
