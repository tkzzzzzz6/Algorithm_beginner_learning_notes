/*
#include <vector>
 * @Author: tkzzzzzz6
 * @Date: 2026-03-22 17:44:27
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-03-22 17:52:23
 */
class Solution {
public:
  int search(vector<int> &nums, int target) {
    int l = 0, r = nums.size();
    while (l < r) {
      int mid = l + ((r - l) >> 1);
      if (nums[mid] < target) {
        l = mid + 1;
      } else if (nums[mid > target) {
        r = mid;
      } else {
        return mid;
      }
    }
    return -1;
  }
};
