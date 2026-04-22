/*
* @acwing app=acwing.cn id=37 lang=C++
*
* 38. 二叉树的镜像
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
    void mirror(TreeNode* root) {
        if(!root)return;
        swap(root->left,root->right);
        mirror(root->left);
        mirror(root->right);
    }
};
// @acwing code end
