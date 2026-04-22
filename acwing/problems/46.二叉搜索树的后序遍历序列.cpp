/*
#include <vector>
* @acwing app=acwing.cn id=44 lang=C++
*
* 46. 二叉搜索树的后序遍历序列
*/

// @acwing code start

class Solution {
public:
    vector<int> seq;

    bool verifySequenceOfBST(vector<int> sequence) {
        seq = sequence;
        return dfs(0,seq.size()-1);
    }

    bool dfs(int l,int r){
        if(l >= r)return true;
        int root = seq[r];

        int k = l;
        while(k < r && seq[k] < root)++k;
        for(int j = k;j<r;++j){
            if(seq[j] < root)return false;
        }

        return dfs(l,k-1) && dfs(k,r-1);
    }

};
// @acwing code end
