/*
 * @Author: tkzzzzzz6
 * @Date: 2026-05-23 17:42:49
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-05-23 17:43:17
 */
#include <bits/stdc++.h>
using namespace std;

struct FlexTask {
    int a;
    int b;
    double unit; // b / a
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    long long total = 0;          // 初始总耗时
    vector<pair<int, int>> rigid; // 普通型: (a, b)
    vector<FlexTask> flex;        // 灵活型

    for (int i = 0; i < n; ++i) {
        int o, t, a, b;
        cin >> o >> t >> a >> b;
        total += t;
        if (o == 1) {
            rigid.emplace_back(a, b);
        } else {
            flex.push_back({a, b, static_cast<double>(b) / a});
        }
    }

    // 0-1 背包：dp[j] 表示恰好消耗 j 杯咖啡能获得的最大缩短量
    // -1.0 表示不可达
    vector<double> dp(m + 1, -1.0);
    dp[0] = 0.0;

    for (auto [a, b] : rigid) {
        for (int j = m; j >= a; --j) {
            if (dp[j - a] >= 0) {
                dp[j] = max(dp[j], dp[j - a] + b);
            }
        }
    }

    // 灵活型按单位收益降序排列
    sort(flex.begin(), flex.end(), [](const FlexTask &x, const FlexTask &y) {
        return x.unit > y.unit;
    });

    double bestGain = 0.0;

    // 枚举普通型消耗的咖啡杯数 j，剩余 m-j 给灵活型
    for (int j = 0; j <= m; ++j) {
        if (dp[j] < 0) continue; // 该状态不可达

        int rem = m - j;     // 剩余咖啡
        double gain = dp[j]; // 当前已缩短的时间

        for (const auto &task : flex) {
            if (rem <= 0) break;
            int k = min(task.a, rem); // 分配给该任务的咖啡杯数
            gain += task.b * 1.0 * k / task.a;
            rem -= k;
        }

        bestGain = max(bestGain, gain);
    }

    double answer = static_cast<double>(total) - bestGain;
    cout << fixed << setprecision(6) << answer << "\n";
    return 0;
}
