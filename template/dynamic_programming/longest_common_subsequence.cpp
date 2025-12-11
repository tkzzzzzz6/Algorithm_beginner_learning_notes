/*
 * 最长公共子序列 (Longest Common Subsequence - LCS)
 * 用途：求两个序列的最长公共子序列
 * 时间复杂度：O(m * n)
 * 空间复杂度：O(m * n)，可优化到 O(min(m, n))
 */

#include <bits/stdc++.h>
using namespace std;

// 基础LCS（返回长度）
int lcs(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[m][n];
}

// 返回LCS字符串
string lcsString(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // 回溯构造LCS
    string lcs_str = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i-1] == s2[j-1]) {
            lcs_str = s1[i-1] + lcs_str;
            i--; j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    return lcs_str;
}

// 空间优化版本
int lcsOptimized(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    vector<int> prev(n + 1, 0), curr(n + 1, 0);

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                curr[j] = prev[j-1] + 1;
            } else {
                curr[j] = max(prev[j], curr[j-1]);
            }
        }
        swap(prev, curr);
    }

    return prev[n];
}

int main() {
    string s1 = "ABCDGH";
    string s2 = "AEDFHR";

    cout << "LCS length: " << lcs(s1, s2) << endl;
    cout << "LCS string: " << lcsString(s1, s2) << endl;

    return 0;
}
