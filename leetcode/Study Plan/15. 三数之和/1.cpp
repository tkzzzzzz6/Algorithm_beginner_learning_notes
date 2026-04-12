/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-12 13:35:46
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-12 13:41:53
 */
/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-12 13:35:46
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-12 13:35:49
 */
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result;
    int n = nums.size();
    for (int i = 0; i < nums.size(); ++i) {
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
          result.push({i, left, right});
          while (nums[left] == nums[left + 1]) {
            left++;
          }
          while (right < n - 1 && nums[right] == nums[right - 1]) {
            right++;
          }
        }
      }
    }
    return result;
  }
};
