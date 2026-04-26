/*
 * @acwing app=acwing.cn id=46 lang=C++
 *
 * 50. 序列化二叉树
 */

// @acwing code start

#include <sstream>
#include <string>

using namespace std;

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
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string s;
        dfs_s(root, s);
        return s;
    }

    void dfs_s(TreeNode *root, string &s) {
        if (!root) {
            s += "n ";
            return;
        } else {
            s += to_string(root->val) + ' ';
        }
        dfs_s(root->left, s);
        dfs_s(root->right, s);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        stringstream ss(data);
        return dfs_d(ss);
    }

    TreeNode *dfs_d(stringstream &ss) {
        string s;
        ss >> s;
        if (s == "n")
            return nullptr;

        auto p = new TreeNode(stoi(s));
        p->left = dfs_d(ss);
        p->right = dfs_d(ss);

        return p;
    }
};
// @acwing code end
