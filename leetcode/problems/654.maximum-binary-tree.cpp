/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-27 21:16:15
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-27 21:26:44
 */
/*
 * @lc app=leetcode.cn id=654 lang=cpp
 * @lcpr version=30204
 *
 * [654] 最大二叉树
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
   public:
    vector<int> nums;
    TreeNode *constructMaximumBinaryTree(vector<int> &_nums) {
        nums = _nums;
        return build(0, nums.size() - 1);
    }

    TreeNode *build(int l, int r) {
        if (l > r)
            return nullptr;
        if (l == r)
            return new TreeNode(nums[l]);

        int maxVal = nums[l];
        int index = l;
        for (int i = l; i <= r; ++i) {
            if (nums[i] > maxVal) {
                maxVal = nums[i];
                index = i;
            }
        }
        auto node = new TreeNode(nums[index]);
        if (index > l) {
            node->left = build(l, index - 1);
        }

        if (index < r) {
            node->right = build(index + 1, r);
        }

        return node;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,1,6,0,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n
// @lcpr case=end

 */
