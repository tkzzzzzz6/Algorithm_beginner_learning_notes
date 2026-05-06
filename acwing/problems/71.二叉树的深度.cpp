/*
 * @acwing app=acwing.cn id=67 lang=C++
 *
 * 71. 二叉树的深度
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
    int treeDepth(TreeNode *root) {
        if (!root)
            return 0;
        return max(treeDepth(root->right), treeDepth(root->left)) + 1;
    }
};
// @acwing code end
