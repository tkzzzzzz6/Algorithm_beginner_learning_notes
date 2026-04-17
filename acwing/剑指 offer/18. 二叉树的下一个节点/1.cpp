/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-17 12:19:42
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-17 12:22:22
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode *father;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL), father(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* p) {
        // p 有右子树的情况,找右子树的最左节点
        if(p->right){
            p = p->right;
            while(p->left)p = p->left;
            return p;
        }
        // p 没有右子树的情况,向上找父节点,直到当前节点是父节点的左节点
        while(p->father && p == p->father->right)p = p->father;
        return p->father;
    }
};
