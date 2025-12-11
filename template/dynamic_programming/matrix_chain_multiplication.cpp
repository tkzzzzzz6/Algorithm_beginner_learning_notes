/*
 * 矩阵链乘法 (Matrix Chain Multiplication)
 * 用途：求矩阵链相乘的最优括号化方案，使乘法次数最少
 * 时间复杂度：O(n^3)
 * 空间复杂度：O(n^2)
 */

#include <bits/stdc++.h>
using namespace std;

// dims[i-1] x dims[i] 是第i个矩阵的维度
int matrixChainOrder(vector<int>& dims) {
    int n = dims.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] +
                          dims[i] * dims[k+1] * dims[j+1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[0][n-1];
}

int main() {
    vector<int> dims = {10, 20, 30, 40, 30};
    cout << "Minimum multiplications: " << matrixChainOrder(dims) << endl;
    return 0;
}
