/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-26 21:11:03
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-27 21:04:44
 */
/*
 * @lc app=leetcode.cn id=106 lang=cpp
 * @lcpr version=30204
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    vector<int> inorder, postorder;
    unordered_map<int, int> pos;
    TreeNode *buildTree(vector<int> &_inorder, vector<int> &_postorder) {
        inorder = _inorder;
        postorder = _postorder;
        int n = inorder.size();
        for (int i = 0; i < n; ++i) {
            pos[inorder[i]] = i;
        }

        return build(0, n - 1, 0, n - 1);
    }

    TreeNode *build(int l1, int r1, int l2, int r2) {
        if (l1 > r1)
            return nullptr;
        int rootVal = postorder[r2];
        auto root = new TreeNode(rootVal);
        int k = pos[rootVal];
        root->left = build(l1, k - 1, l2, l2 + (k - l1) - 1);
        root->right = build(k + 1, r1, l2 + (k - l1), r2 - 1);
        return root;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [9,3,15,20,7]\n[9,15,7,20,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */
