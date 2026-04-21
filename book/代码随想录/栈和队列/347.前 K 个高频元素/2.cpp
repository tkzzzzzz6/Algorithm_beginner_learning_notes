/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-19 19:14:12
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-19 19:21:41
 */
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
        for(auto x:nums){
            mp[x]++;
        }

        int n = nums.size();
        vector<int> res;
        vector<vector<int>>bucket(n+1);

        for(auto &[num,cnt] : mp){
            bucket[cnt].push_back(num);
        }

        for(int i = n;i>=1&&res.size() < k;--i){
            for(auto num:bucket[i]){
                res.push_back(num);
                if(res.size() == k)
                    break;
            }
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
