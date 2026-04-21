/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-19 00:11:11
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-19 13:44:15
 */
/*
 * @lc app=leetcode.cn id=1855 lang=cpp
 * @lcpr version=30204
 *
 * [1855] 下标对中的最大距离
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
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int res = 0;

        int i = 0;
        for(int j = 0;j<n2;++j){
            while(i<n1 && nums1[i] > nums2[j]){
                ++i;
            }
            if(i<n1){
                res = max(res,j-i);
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [55,30,5,4,2]\n[100,20,10,10,5]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2]\n[10,10,1]\n
// @lcpr case=end

// @lcpr case=start
// [30,29,19,5]\n[25,25,25,25,25]\n
// @lcpr case=end

 */
