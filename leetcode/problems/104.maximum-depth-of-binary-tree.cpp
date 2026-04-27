/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-26 13:58:47
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-26 13:59:07
 */
/*
 * @lc app=leetcode.cn id=104 lang=cpp
 * @lcpr version=30204
 *
 * [104] 二叉树的最大深度
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (!root)
      return 0;
    // int lhegiht = maxDepth(root->left);
    // int rheight = maxDepth(root->right);

    // return 1 + max(lhegiht, rheight);
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
  }
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2]\n
// @lcpr case=end

 */
