/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-23 17:42:49
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-23 18:08:38
 */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <iomanip>

using namespace std;

struct FlexTask {
    int a, b;
    double unit; // b/a
    FlexTask(int a_ = 0, int b_ = 0) : a(a_), b(b_) {
        unit = (a == 0) ? 0.0 : static_cast<double>(b) / a;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    long long total = 0;
    vector<FlexTask> flex;
    vector<pair<int, int>> rigid;

    for (int i = 0; i < n; ++i) {
        int o, t, a, b;
        cin >> o >> t >> a >> b;
        total += t;
        if (o == 0) { // 灵活型
            flex.push_back(FlexTask(a, b));
        } else {
            rigid.emplace_back(a, b);
        }
    }

    vector<double> dp(m + 1, -1.0);
    dp[0] = 0.0;

    for (auto [a, b] : rigid) {
        for (int j = m; j >= a; --j) {
            if (dp[j - a] >= 0) {
                dp[j] = max(dp[j], dp[j - a] + b);
            }
        }
    }

    sort(flex.begin(), flex.end(), [](const FlexTask &x, const FlexTask &y) {
        return x.unit > y.unit;
    });

    double bestGain = 0.0;

    for (int j = 0; j <= m; ++j) {
        if (dp[j] < 0) continue;

        int rem = m - j;
        double gain = dp[j];

        for (const auto &task : flex) {
            if (rem == 0) break;
            if (task.a == 0) continue;
            int k = min(task.a, rem);
            gain += static_cast<double>(task.b) * k / task.a;
            rem -= k;
        }

        bestGain = max(bestGain, gain);
    }

    double res = static_cast<double>(total) - bestGain;

    cout << fixed << setprecision(6) << res << endl;

    return 0;
}
