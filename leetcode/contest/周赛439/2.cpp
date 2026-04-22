#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestPalindromeSubseq(string s, int k)
    {
        int n = s.length();

        // dp[i][j][remain] 表示考虑 s[i...j]，最多剩余 'remain' 次操作的最长回文子序列的长度
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, -1)));

        return solve(s, 0, n - 1, k, dp);
    }

private:
    int solve(const string &s, int i, int j, int remain, vector<vector<vector<int>>> &dp)
    {
        // 基本情况
        if (i > j)
            return 0;
        if (i == j)
            return 1;

        // 如果已经计算过
        if (dp[i][j][remain] != -1)
            return dp[i][j][remain];

        int result = 0;

        // 情况 1: 跳过两个字符
        result = max(solve(s, i + 1, j - 1, remain, dp), result);

        // 情况 2: 跳过左字符
        result = max(solve(s, i + 1, j, remain, dp), result);

        // 情况 3: 跳过右字符
        result = max(solve(s, i, j - 1, remain, dp), result);

        // 情况 4: 包含两个字符
        if (s[i] == s[j])
        {
            // 如果字符匹配，不需要操作
            result = max(solve(s, i + 1, j - 1, remain, dp) + 2, result);
        }
        else if (remain > 0)
        {
            // 尝试通过一次操作使字符匹配
            // 我们可以改变 s[i] 或 s[j]
            result = max(solve(s, i + 1, j - 1, remain - 1, dp) + 2, result);
        }

        dp[i][j][remain] = result;
        return result;
    }
};

int main()
{
    Solution solution;

    // 示例 1
    string s1 = "abced";
    int k1 = 2;
    cout << "示例 1: " << solution.longestPalindromeSubseq(s1, k1) << endl; // 期望: 3

    // 示例 2
    string s2 = "aaazzz";
    int k2 = 4;
    cout << "示例 2: " << solution.longestPalindromeSubseq(s2, k2) << endl; // 期望: 6

    return 0;
}
