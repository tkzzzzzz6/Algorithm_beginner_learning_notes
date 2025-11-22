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

    vector<long long> dp(n + 1, 0);
    vector<long long> prefixSum(n + 1, 0);
    dp[0] = 1;
    prefixSum[0] = 1;

    int lastLPos = 0;

    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == 'L')
        {
            lastLPos = i;
        }

        if (lastLPos == 0)
        {
            // 前i个字符中没有L
            dp[i] = 0;
        }
        else
        {
            // 可以从位置1到lastLPos的任何位置开始最后一个日程块
            // dp[i] = sum(dp[0] + dp[1] + ... + dp[lastLPos-1])
            dp[i] = prefixSum[lastLPos];
        }

        prefixSum[i] = (prefixSum[i - 1] + dp[i]) % MOD;
    }

    cout << dp[n] << endl;

    return 0;
}