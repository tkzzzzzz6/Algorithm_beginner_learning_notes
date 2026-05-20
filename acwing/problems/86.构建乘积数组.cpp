/*
 * @acwing app=acwing.cn id=82 lang=C++
 *
 * 86. 构建乘积数组
 */

// @acwing code start

class Solution {
   public:
    vector<int> multiply(const vector<int> &A) {
        if (A.empty())
            return vector<int>();
        int n = A.size();
        vector<int> res(n, 1);

        // 左乘左边,不包含自己
        for (int i = 1, p = A[0]; i < n; ++i) {
            res[i] = p;
            p *= A[i];
        }

        // 右乘右边
        for (int i = n - 2, p = A[n - 1]; i >= 0; --i) {
            res[i] *= p;
            p *= A[i];
        }

        return res;
    }
};
// @acwing code end
