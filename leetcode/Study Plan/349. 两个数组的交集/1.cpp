/*
#include <vector>
 * @Author: tkzzzzzz6
 * @Date: 2026-04-11 09:39:48
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-11 09:42:55
 */
class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    unordered_set<int> result; // 自动去重
    int hash[10001] = {0}; // 题目说了num1/2中元素的大小在 0- 1000
    for (auto x : nums1) {
      hash[x] = 1;
    }
    for (auto x : nums2) {
      if (hash[x] == 1)
        result.insert(x);
    }
    return vector<int>(result.begin(), result.end());
  }
};
