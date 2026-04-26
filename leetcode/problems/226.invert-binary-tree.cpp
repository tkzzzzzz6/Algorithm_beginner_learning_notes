/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-23 15:04:03
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-23 15:44:44
 */
/*
 * @lc app=leetcode.cn id=226 lang=cpp
 * @lcpr version=30204
 *
 * [226] 翻转二叉树
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
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
class Solution {
   public:
    TreeNode *invertTree(TreeNode *root) {
        if (!root)
            return root;

        // 前序遍历
        // swap(root->left, root->right);
        // invertTree(root->left);
        // invertTree(root->right);
        // 后序遍历
        // invertTree(root->left);
        // invertTree(root->right);
        // swap(root->left, root->right);
        // // 中序遍历
        // invertTree(root->left);
        // swap(root->left, root->right);
        // invertTree(root->left);
        // // 层次遍历
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            swap(t->left, t->right);
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
        return root;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,2,7,1,3,6,9]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
