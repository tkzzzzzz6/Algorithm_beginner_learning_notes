/*
* @acwing app=acwing.cn id=35 lang=C++
*
* 37. 树的子结构
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
    bool hasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if(!pRoot1 || !pRoot2)return false;
        if(isSame(pRoot1,pRoot2))return true;
        return hasSubtree(pRoot1->left,pRoot2) || hasSubtree(pRoot1->right,pRoot2);
    }

    bool isSame(TreeNode* root1,TreeNode* root2){
        if(!root2)return true;
        if(!root1 || root1->val != root2->val)return false;
        return isSame(root1->left,root2->left) && isSame(root1->right,root2->right);
    }
};
// @acwing code end
