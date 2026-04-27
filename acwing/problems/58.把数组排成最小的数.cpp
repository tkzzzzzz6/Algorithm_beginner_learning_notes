/*
 * @acwing app=acwing.cn id=54 lang=C++
 *
 * 58. 把数组排成最小的数
 */

// @acwing code start

class Solution {
public:
  static bool cmp(int a, int b) {
    string sa = to_string(a), sb = to_string(b);
    return sa + sb < sb + sa;
  }

  string printMinNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end(), cmp);
    string res;
    for (auto num : nums) {
      res += to_string(num);
    }

    return res;
  }
};
// @acwing code end
