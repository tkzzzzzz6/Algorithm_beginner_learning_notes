/*
 * @Author: tkzzzzzz6
 * @Date: 2026-01-24 22:58:34
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-01-24 22:58:37
 */

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

typedef pair<int, int> pii;
typedef pair<int, char> pic;

const int N = 16;
const int mod = 1e9 + 7;

int n, a[N][N];
int dp[1 << N][N][3];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < n; i++)
        dp[1 << i][i][0] = 0;
    for (int i = 1; i < (1 << n); i++) {
        for (int j = 0; (1 << j) <= i; j++) {
            if (((1 << j) & i) == 0)
                continue;
            int x = (1 << j) ^ i;
            for (int k = 0; (1 << k) <= x; k++) {
                if (((1 << k) & x) == 0)
                    continue;
                dp[i][j][0] = min(dp[i][j][0], dp[x][k][0] + a[k][j]);
                dp[i][j][1] = min(dp[i][j][1], min(dp[x][k][0], dp[x][k][1] + a[k][j]));
                dp[i][j][2] = min(dp[i][j][2], min(dp[x][k][2] + a[k][j], dp[x][k][1] + 2 * a[k][j]));
            }
        }
    }
    int ans = 0x3fffffff;
    for (int i = 0; i < n; i++)
        ans = min(ans, dp[(1 << n) - 1][i][2]);
    cout << ans;
    return 0;
}
