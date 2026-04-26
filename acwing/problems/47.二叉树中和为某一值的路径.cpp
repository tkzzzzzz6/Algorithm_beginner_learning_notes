#include <vector>
/*
 * @acwing app=acwing.cn id=45 lang=C++
 *
 * 47. 二叉树中和为某一值的路径
 */

// @acwing code start

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  vector<vector<int>> res;
  vector<int> tracker;
  vector<vector<int>> findPath(TreeNode *root, int sum) {
    dfs(root, sum);
    return res;
  }

  void dfs(TreeNode *root, int sum) {
    if (!root)
      return;
    sum -= root->val;
    tracker.push_back(root->val);
    if (!root->right && !root->left && !sum) {
      res.push_back(tracker);
    }
    dfs(root->left, sum);
    dfs(root->right, sum);
    tracker.pop_back();
  }
};
// @acwing code end
