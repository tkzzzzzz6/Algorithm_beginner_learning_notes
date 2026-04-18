#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;

class CombinationDP {
private:
    vector<vector<long long>> dp;
public:
    CombinationDP(int maxN) {
        dp.resize(maxN + 1, vector<long long>(maxN + 1, 0));
        for (int i = 0; i <= maxN; ++i) {
            dp[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }
    long long getC(int n, int k) {
        if (k > n || k < 0) return 0;
        return dp[n][k];
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int n;
    cin >> n;

    map<int, int> cnt;  // ͳÿֵֵĴ
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        cnt[a]++;
    }

    CombinationDP cdp(n);
    ll ans = 0;

    // öֵ (val1, val2)
    for (auto& [val1, c1] : cnt) {
        for (auto& [val2, c2] : cnt) {
            if (val1 < val2) {  // ظ
                // 1: ѡ2val1 + 1val2
                ans += cdp.getC(c1, 2) * c2;
                // 2: ѡ1val1 + 2val2
                ans += c1 * cdp.getC(c2, 2);
            }
        }
    }

    cout << ans << '\n';
    return 0;
}

