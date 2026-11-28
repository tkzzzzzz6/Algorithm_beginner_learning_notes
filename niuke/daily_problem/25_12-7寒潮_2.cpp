#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    const int Unknown = -999;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> dp1(n, vector<int>(101, -1)); // 寒潮次数的最大值
    vector<vector<int>> dp2(n, vector<int>(101, 10001)); // 寒潮次数的最小值
    if (a[0] != Unknown) {
        int idx = a[0] + 50;
        dp1[0][idx] = 0;
        dp2[0][idx] = 0;
    } else {
        for (int i = 0; i <= 100; i++) {
            dp1[0][i] = 0;
            dp2[0][i] = 0;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= 100; j++) {
            if (a[i] != Unknown && j != a[i] + 50)
                continue;
            for (int k = 0; k <= 100; k++) {
                if (a[i - 1] != Unknown && k != a[i - 1] + 50)
                    continue;
                int inc;
                if (k - j >= x)
                    inc = 1;
                else
                    inc = 0;
                dp1[i][j] = max(dp1[i][j], dp1[i - 1][k] + inc);
                dp2[i][j] = min(dp2[i][j], dp2[i - 1][k] + inc);
            }
        }
    }

    int ans_max = *max_element(dp1[n - 1].begin(), dp1[n - 1].end());
    int ans_min = *min_element(dp2[n - 1].begin(), dp2[n - 1].end());
    cout << ans_max << " " << ans_min << endl;

}
