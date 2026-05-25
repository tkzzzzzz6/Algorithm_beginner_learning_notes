/*
 * @lc app=leetcode.cn id=34 lang=cpp
 * @lcpr version=30204
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
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
    int lower_bound1(vector<int>& nums,int target){
        // 闭区间版本
        int left = 0,right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }

        return left;
    }

    int lower_bound2(vector<int>& nums,int target){
    // 左闭右开区间
    int left = 0,right = nums.size();
    while(left < right){
        int mid = left + (right - left) / 2;
        if(nums[mid] < target) left = mid + 1;
        else right = mid;
    }

        return left;
    }

    int lower_bound3(vector<int>& nums,int target){
    // 开区间
    int left = -1,right = nums.size();
    while(left+1 < right){
        int mid = left + (right - left) / 2;
        if(nums[mid] < target) left = mid;
        else right = mid;
    }

        return right;
    }



    vector<int> searchRange(vector<int>& nums, int target) {
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,7,7,8,8,10]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,7,7,8,8,10]\n6\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */
