/*
 * @lc app=leetcode.cn id=347 lang=cpp
 * @lcpr version=30204
 *
 * [347] 前 K 个高频元素
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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();

        for(int i = 0;i<n;++i)
            mp[nums[i]]++;

        auto cmp = [](const auto&a,const auto&b){
            return a.second > b.second;
        };

        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);

        for(unordered_map<int,int>::iterator it = mp.begin();it != mp.end();++it){
            pq.push(*it);
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> res(k);
        for(int i = k-1;i>=0;--i){
            res[i] = pq.top().first;
            pq.pop();
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1,2,2,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1,2,1,2,3,1,3,2]\n2\n
// @lcpr case=end

 */
