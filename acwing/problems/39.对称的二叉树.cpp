/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-22 10:58:49
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-22 11:01:05
 */
/*
* @acwing app=acwing.cn id=38 lang=C++
*
* 39. 对称的二叉树
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
    bool isSymmetric(TreeNode* root) {
        return !root || dfs(root->left,root->right);
    }

    bool dfs(TreeNode* p,TreeNode* q){
        if(!p || !q)return !p && !q;

        return (p->val == q->val) && dfs(p->left,q->right) && dfs(p->right,q->left);
    }
};
// @acwing code end
