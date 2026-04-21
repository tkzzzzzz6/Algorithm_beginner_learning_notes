#include <unordered_map>
#include <vector>
/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-11 11:15:02
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-11 11:22:51
 */
class Solution {
public:
  int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,vector<int> &nums4) {
    unordered_map<int, int> umap;
    int count = 0;
    for (auto a : nums1) {
      for (auto b : nums2) {
        umap[a + b]++;
      }
    }

    for (auto c : nums3) {
      for (auto d : nums4) {
        if (umap.find(-c - d) != umap.end()) {
          count += umap[-c - d];
        }
      }
    }
    return count;
  }
};
