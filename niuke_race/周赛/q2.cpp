#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

long long fastPow(long long base, int exp)
{
    long long result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

int solve(int n, int m)
{
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    
    for (int i = 1; i <= n; ++i)
    {
        vector<long long> new_dp(n + 1, 0);
        for (int j = 1; j <= n; ++j)
        {
            new_dp[j] = (dp[j-1] + j * dp[j]) % MOD;
        }
        dp = new_dp;
    }
    
    long long result = 0;
    for (int k = 1; k <= n; ++k)
    {
        long long term = (dp[k] * fastPow(m - k + 1, n - k)) % MOD;
        if (k % 2 == 0) term = MOD - term;
        result = (result + term) % MOD;
    }
    
    return result;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        cout << solve(n, m) << endl;
    }
    return 0;
}