/*
 * @lc app=leetcode.cn id=106 lang=cpp
 * @lcpr version=30204
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
  vector<int> inorder, postorder;
  unordered_map<int, int> hash;
  TreeNode *buildTree(vector<int> &_inorder, vector<int> &_postorder) {
    inorder = _inorder;
    postorder = _postorder;
    for (int i = 0; i < inorder.size(); ++i) {
      hash[inorder[i]] == i;
    }

    auto dummy = new TreeNode(-1);
    build(dummy, 0, inorder.size() - 1, 0, posterorder.size() - 1);
  }

  void build(TreeNode *root, int l1, int r1, int l2, int r2) {
    int reslove = postprder[r2];
    l1 = hash[resolve], l2 = build(root->left, )
  }
};
// @lc code=end

/*
// @lcpr case=start
// [9,3,15,20,7]\n[9,15,7,20,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */
