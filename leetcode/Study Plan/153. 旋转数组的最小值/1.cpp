/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-17 14:25:15
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-17 14:25:17
 */
/*
 * @lc app=leetcode.cn id=153 lang=cpp
 * @lcpr version=30204
 *
 * [153] 寻找旋转排序数组中的最小值
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
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)return -1;
        int left = 0,right = n - 1;
        while(left < right){
            int mid = left + ((right - left) >> 1);
            if(nums[right] < nums[mid])
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,4,5,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [4,5,6,7,0,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [11,13,15,17]\n
// @lcpr case=end

 */
