/*
 * @lc app=leetcode.cn id=257 lang=cpp
 * @lcpr version=30204
 *
 * [257] 二叉树的所有路径
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
  void traverse(TreeNode *root, vector<int> &path, vector<string> &res) {
    if (!root)
      return;

    path.push_back(root->val);
    if (!root->left && !root->right) {
      string s;
      int size = path.size() - 1;
      int i = 0;
      for (; i < size; ++i) {
        s += to_string(path[i]) + "->";
      }
      s += to_string(path[i]);

      res.push_back(s);
    }
    if (root->left) {
      traverse(root->left, path, res);
    }

    if (root->right) {
      traverse(root->right, path, res);
    }
    path.pop_back();
  }
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> res;
    vector<int> path;
    traverse(root, path, res);

    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,null,5]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
