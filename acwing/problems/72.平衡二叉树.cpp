/*
 * @acwing app=acwing.cn id=68 lang=C++
 *
 * 72. 平衡二叉树
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
    bool ans = true;

    bool isBalanced(TreeNode *root) {
        dfs(root);
        return ans;
    }

    int dfs(TreeNode *root) {
        if (!root)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        if (abs(left - right) > 1) {
            ans = false;
            return -1;
        }

        return max(left, right) + 1;
    }
};
// @acwing code end
