#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    // dp[i] 表示前i个字符的合法划分方案数
    vector<long long> dp(n + 1, 0);
    dp[0] = 1; // 空串有1种方案（什么都不划分）

    // 记录每个位置左边最近的L的位置（1-indexed）
    vector<int> lastL(n + 1, 0);
    int lastLPos = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == 'L')
        {
            lastLPos = i;
        }
        lastL[i] = lastLPos;
    }

    // 动态规划
    for (int i = 1; i <= n; i++)
    {
        if (lastL[i] == 0)
        {
            // 前i个字符中没有L，无法划分
            dp[i] = 0;
            continue;
        }

        // 枚举最后一个日程块的起始位置j
        // 要使[j, i]包含至少一个L，j必须 <= lastL[i]
        for (int j = 1; j <= lastL[i]; j++)
        {
            dp[i] = (dp[i] + dp[j - 1]) % MOD;
        }
    }

    cout << dp[n] << endl;

    return 0;
}