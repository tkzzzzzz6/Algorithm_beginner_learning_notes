/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-26 14:36:27
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-26 14:36:29
 */
/*
 * @lc app=leetcode.cn id=110 lang=cpp
 * @lcpr version=30204
 *
 * [110] 平衡二叉树
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
  int getHeight(TreeNode *root) {
    if (!root)
      return 0;
    int lheight = getHeight(root->left);
    if (lheight == -1)
      return -1;
    int rheight = getHeight(root->right);
    if (rheight == -1)
      return -1;

    if (abs(lheight - rheight) > 1)
      return -1;
    else {
      return 1 + max(lheight, rheight);
    }
  }

  bool isBalanced(TreeNode *root) {
    if (getHeight(root) == -1)
      return false;
    return true;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,3,3,null,null,4,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
