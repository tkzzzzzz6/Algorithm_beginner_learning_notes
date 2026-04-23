/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-22 00:15:14
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-22 16:27:58
 */
/*
 * @lc app=leetcode.cn id=145 lang=cpp
 * @lcpr version=30204
 *
 * [145] 二叉树的后序遍历
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
   public:
    vector<int> res;

    void reverse_array(vector<int> &res) {
        int l = 0, r = res.size() - 1;
        while (l < r) {
            swap(res[l], res[r]);
            ++l;
            --r;
        }
    }

    vector<int> postorderTraversal(TreeNode *root) {
        if (!root)
            return res;

        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty()) {
            auto t = st.top();
            st.pop();

            if (!t) {
                continue;
            } else {
                res.push_back(t->val);
            }

            st.push(t->left);
            st.push(t->right);
        }

        reverse_array(res);
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,null,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,null,8,null,null,6,7,9]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
