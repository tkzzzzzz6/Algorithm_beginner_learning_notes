#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    int n = a.size();
    int m = b.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1,0));

    for (int i = 1; i < n; ++i) dp[i][0] = i;
    for (int j = 1; j < m; ++j) dp[0][j] = j;

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(
                               dp[i - 1][j - 1], // Ìæ»»
                               dp[i - 1][j],     // É¾³ý
                               dp[i][j - 1]      // Ôö¼Ó
                               )
                           + 1;
            }
        }
    }

    cout << dp[n][m] << '\n';

    
}