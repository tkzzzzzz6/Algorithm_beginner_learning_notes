/*
 * @acwing app=acwing.cn id=88 lang=C++
 *
 * 54. 数据流中的中位数
 */

// @acwing code start

#include <functional>
#include <vector>
class Solution {
   public:
    priority_queue<int> max_heap;                                      // 大顶堆，存储较小的一半
    priority_queue<int, std::vector<int>, std::greater<int>> min_heap; // 小顶堆，存储较大的一半
    void insert(int num) {
        max_heap.push(num);
        if (min_heap.size() && max_heap.top() > min_heap.top()) {
            auto maxv = max_heap.top(), minv = min_heap.top();
            max_heap.pop(), min_heap.pop();
            max_heap.push(minv), min_heap.push(maxv);
        }
        if (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }

    double getMedian() {
        if (max_heap.size() + min_heap.size() & 1) {
            return max_heap.top();
        } else {
            return (max_heap.top() + min_heap.top()) / 2.0;
        }
    }
};
// @acwing code end
