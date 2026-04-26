/*
 * @lc app=leetcode.cn id=222 lang=cpp
 * @lcpr version=30204
 *
 * [222] 完全二叉树的节点个数
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
  int countNodes(TreeNode *root) {
    if (!root)
      return 0;
    auto left = root->left;
    auto right = root->right;
    int leftDepth = 0, rightDepth = 0;
    while (left)
      left = left->left, leftDepth++;
    while (right)
      right = right->right, rightDepth++;

    if (leftDepth == rightDepth)
      return (2 << leftDepth) - 1;

    int lcnt = countNodes(root->left);
    int rcnt = countNodes(root->right);

    return lcnt + rcnt + 1;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5,6]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
