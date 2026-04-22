/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-22 13:47:29
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-22 13:47:47
 */
/*
* @acwing app=acwing.cn id=43 lang=C++
*
* 45. 之字形打印二叉树
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
        bool reverseFlag = false;
        while(q.size()){
            auto t = q.front();
            q.pop();

            if(t == nullptr){
                if(reverseFlag)reverse(level.begin(),level.end());
                res.push_back(level);
                reverseFlag = !reverseFlag;
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
