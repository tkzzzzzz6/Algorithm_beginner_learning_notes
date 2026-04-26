/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-25 11:33:20
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-25 11:36:00
 */
/*
 * @acwing app=acwing.cn id=87 lang=C++
 *
 * 49. 二叉搜索树与双向链表
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
#include <utility>
using namespace std;
class Solution {
   public:
    TreeNode *convert(TreeNode *root) {
        if (!root)
            return nullptr;
        auto res = dfs(root);
        return res.first;
    }

    pair<TreeNode *, TreeNode *> dfs(TreeNode *root) {
        if (!root->left && !root->right)
            return {root, root};
        if (root->left && root->right) {
            auto lslide = dfs(root->left), rslide = dfs(root->right);
            lslide.second->right = root, root->left = lslide.second;
            rslide.first->left = root, root->right = rslide.first;
            return {lslide.first, rslide.second};
        }
        if (root->left) {
            auto lslide = dfs(root->left);
            lslide.second->right = root, root->left = lslide.second;
            return {lslide.first, root};
        }
        if (root->right) {
            auto rslide = dfs(root->right);
            rslide.first->left = root, root->right = rslide.first;
            return {root, rslide.second};
        }

        return {nullptr, nullptr};
    }
};
// @acwing code end
