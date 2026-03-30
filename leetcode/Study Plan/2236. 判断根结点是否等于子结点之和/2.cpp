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

//  如果根节点的儿子节点也有自己的儿子节点的话,如何判断对应的子树是不是也是满足子树的根节点的值等于对应子树节点和的方法
class Solution {
public:
  bool checkTree(TreeNode *root) {
    if(root->left == nullptr && root->right == nullptr)
        return true;
    return root->val == root->left->val + root->right->val && checkTree(root->right) && checkTree(root->left);
  }
};
