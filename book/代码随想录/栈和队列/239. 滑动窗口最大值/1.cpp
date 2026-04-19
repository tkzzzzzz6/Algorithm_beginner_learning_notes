/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-19 13:04:13
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-19 13:17:06
 */
/*
 * @lc app=leetcode.cn id=239 lang=cpp
 * @lcpr version=30204
 *
 * [239] 滑动窗口最大值
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:

    class MyQueue{
        public:
            deque<int> q;
            
            void pop(int x){
                if(!q.empty() && q.front() == x)q.pop_front(); //队首是当前窗口的最大值,与 front 对比不能和 back 对比
            }

            void push(int x){
                while(!q.empty() && q.back() < x){
                    q.pop_back();
                }
                q.push_back(x);
            }

            int front(){
                return q.front();
            }
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue mq;
        vector<int> res;
        int n = nums.size();

        for(int i = 0;i<k;++i)mq.push(nums[i]);
        res.push_back(mq.front());

        for(int i = k;i<n;++i){
            mq.pop(nums[i-k]);
            mq.push(nums[i]);
            res.push_back(mq.front());
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,-1,-3,5,3,6,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */
