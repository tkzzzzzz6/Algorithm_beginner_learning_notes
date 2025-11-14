#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

int addmod(int a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T))
        return 0;

    // 先读所有测试，记录最大 n 和最大 t
    vector<pair<int, int>> qs(T);
    int maxN = 0;
    int maxT = 0;
    for (int ti = 0; ti < T; ++ti)
    {
        int n, t;
        cin >> n >> t;
        qs[ti] = {n, t};
        maxN = max(maxN, n);
        maxT = max(maxT, t);
    }

    // dp[i][j] = 长度为 i，总 val 为 j 的段长序列数量
    vector<vector<int>> dp(maxN + 1, vector<int>(maxT + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i <= maxN; ++i)
    {
        for (int j = 0; j <= maxT; ++j)
        {
            int cur = dp[i][j];
            if (!cur)
                continue;
            // 枚举下一段长度 len
            for (int len = 1; i + len <= maxN; ++len)
            {
                int addVal = len * (len - 1) / 2;
                if (j + addVal > maxT)
                    break; // 后面 len 更大，addVal 只会更大，直接停
                dp[i + len][j + addVal] = addmod(dp[i + len][j + addVal], cur);
            }
        }
    }

    // 回答每个测试
    for (int ti = 0; ti < T; ++ti)
    {
        int n = qs[ti].first;
        int t = qs[ti].second;
        // dp[n][t] 即段长方案数，每个段长方案对应 2 个实际字符串（首位 0 或 1）
        ll ways = dp[n][t];
        ll ans = (ways * 2) % MOD;
        cout << ans << '\n';
    }

    return 0;
}
