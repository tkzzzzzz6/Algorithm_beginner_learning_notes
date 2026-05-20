/*
 * @acwing app=acwing.cn id=84 lang=C++
 *
 * 88. 树中两个结点的最低公共祖先
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root)
            return nullptr;
        if (root == p || root == q)
            return root;
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        if (left && right)
            return root;
        if (left == nullptr)
            return right;
        if (right == nullptr)
            return left;
    }
};
// @acwing code end
