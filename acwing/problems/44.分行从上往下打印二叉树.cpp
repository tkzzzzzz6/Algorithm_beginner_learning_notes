#include <vector>
/*
* @acwing app=acwing.cn id=42 lang=C++
*
* 44. 分行从上往下打印二叉树
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
    vector<vector<int>> printFromTopToBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)return res;

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);

        vector<int> level;
        while(q.size()){
            auto t = q.front();
            q.pop();

            if(t == nullptr){
                res.push_back(level);
                level.clear();
                if(!q.empty()){
                    q.push(nullptr);
                }
            }else{
                level.push_back(t->val);
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
        }

        return res;
    }
};
// @acwing code end
