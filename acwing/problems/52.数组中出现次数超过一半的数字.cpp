#include <vector>
/*
 * @acwing app=acwing.cn id=48 lang=C++
 *
 * 52. 数组中出现次数超过一半的数字
 */

// @acwing code start

class Solution {
public:
  int moreThanHalfNum_Solution(vector<int> &nums) {
    int cnt = 0, val = -1;
    for (int i = 0; i < nums.size(); ++i) {
      if (cnt <= 0)
        val = nums[i];
      if (nums[i] == val)
        cnt++;
      else
        cnt--;
    }
    return val;
  }
};
// @acwing code end
