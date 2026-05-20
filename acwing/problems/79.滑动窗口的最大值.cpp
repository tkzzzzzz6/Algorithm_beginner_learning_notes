/*
 * @acwing app=acwing.cn id=75 lang=C++
 *
 * 79. 滑动窗口的最大值
 */

// @acwing code start

class Solution {
   public:
    vector<int> maxInWindows(vector<int> &nums, int k) {
        vector<int> res;
        deque<int> q; // 队列存的是元素下标
        for (int i = 0; i < nums.size(); ++i) {
            while (q.size() && q.front() <= i - k)
                q.pop_front(); // 窗口易懂
            while (q.size() && nums[q.back()] <= nums[i])
                q.pop_back(); // 插入的大元素抵消前面的小元素
            q.push_back(i);

            if (i >= k - 1)
                res.push_back(nums[q.front()]);
        }

        return res;
    }
};
// @acwing code end
