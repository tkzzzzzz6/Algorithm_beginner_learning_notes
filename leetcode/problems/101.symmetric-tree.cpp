/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-26 13:31:46
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-26 13:31:48
 */
/*
 * @lc app=leetcode.cn id=101 lang=cpp
 * @lcpr version=30204
 *
 * [101] 对称二叉树
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
  bool compare(TreeNode *l, TreeNode *r) {
    if (!l && !r)
      return true;
    if (!l || !r)
      return false;
    if (l->val != r->val)
      return false;

    bool inside = compare(l->left, r->right);
    bool outside = compare(l->right, r->left);
    return inside && outside;
  }

  bool isSymmetric(TreeNode *root) {
    if (!root)
      return true;
    return compare(root->left, root->right);
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,2,3,4,4,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,null,3,null,3]\n
// @lcpr case=end

 */
