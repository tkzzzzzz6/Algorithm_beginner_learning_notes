/*
 * @acwing app=acwing.cn id=49 lang=C++
 *
 * 53. 最小的k个数
 */

// @acwing code start

#include <algorithm>
#include <queue>
#include <vector>
class Solution {
public:
  vector<int> getLeastNumbers_Solution(vector<int> input, int k) {
    std::priority_queue<int> heap;
    std::vector<int> res;

    for (auto x : input) {
      heap.push(x);
      if (heap.size() > k)
        heap.pop();
    }

    while (!heap.empty()) {
      res.push_back(heap.top());
      heap.pop();
    }
    std::reverse(res.begin(), res.end());
    return res;
  }
};
// @acwing code endnt
