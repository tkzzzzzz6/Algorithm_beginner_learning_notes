/*
 * @acwing app=acwing.cn id=66 lang=C++
 *
 * 70. 二叉搜索树的第k个结点
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
    TreeNode *ans;

    TreeNode *kthNode(TreeNode *root, int k) {
        dfs(root, k);
        return ans;
    }

    void dfs(TreeNode *root, int &k) {
        if (!root)
            return;
        dfs(root->left, k);
        k--;
        if (!k)
            ans = root;
        if (k)
            dfs(root->right, k);
    }
};
// @acwing code end
