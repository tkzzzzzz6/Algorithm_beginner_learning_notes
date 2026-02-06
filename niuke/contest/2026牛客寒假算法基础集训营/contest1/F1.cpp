/*
 * @Author: tkzzzzzz6
 * @Date: 2026-02-03 17:27:17
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-02-03 17:27:19
 */
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

static const int MAXK = 15;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 预计算 10^i
    static int64 pw10[MAXK + 1];
    pw10[0] = 1;
    for (int i = 1; i <= MAXK; i++)
        pw10[i] = pw10[i - 1] * 10;

    auto to_digits = [&](int64 x, int k) {
        // 转成恰好 k 位（无前导 0，因为我们传入的 x 一定是 k 位范围内）
        string s = to_string(x);
        // 保险：如果长度不足，补 0（正常不会发生，因为 x>=10^{k-1}）
        if ((int)s.size() < k)
            s = string(k - (int)s.size(), '0') + s;
        return s;
    };

    auto solve_one_k = [&](int64 L, int64 R, int k) -> int64 {
        // digit DP：最大化 rev(x) = sum digit[pos] * 10^pos (pos 从 0=最高位到 k-1=最低位)
        // 注意：pos 的权重是 10^pos（pos 越大越重要）
        string lo = to_digits(L, k);
        string hi = to_digits(R, k);

        // dp[pos][tightL][tightH] = 从 pos 开始（含 pos）能得到的最大 rev 贡献
        // 用 -1 表示不可达
        static int64 dp[MAXK + 1][2][2];
        for (int pos = 0; pos <= k; pos++)
            for (int tl = 0; tl < 2; tl++)
                for (int th = 0; th < 2; th++)
                    dp[pos][tl][th] = -1;

        dp[0][1][1] = 0;

        for (int pos = 0; pos < k; pos++) {
            for (int tl = 0; tl < 2; tl++) {
                for (int th = 0; th < 2; th++) {
                    if (dp[pos][tl][th] < 0)
                        continue;

                    int lowD = tl ? (lo[pos] - '0') : 0;
                    int highD = th ? (hi[pos] - '0') : 9;

                    for (int d = lowD; d <= highD; d++) {
                        // 最后一位不能为 0（否则翻转会产生前导 0 被删，通常不会成为最大）
                        if (pos == k - 1 && d == 0)
                            continue;

                        int ntl = tl && (d == lowD);
                        int nth = th && (d == highD);

                        // rev 的贡献：digit[pos] * 10^pos
                        int64 val = dp[pos][tl][th] + (int64)d * pw10[pos];
                        dp[pos + 1][ntl][nth] = max(dp[pos + 1][ntl][nth], val);
                    }
                }
            }
        }

        int64 best = -1;
        for (int tl = 0; tl < 2; tl++)
            for (int th = 0; th < 2; th++)
                best = max(best, dp[k][tl][th]);
        return best;
    };

    int T;
    cin >> T;
    while (T--) {
        int64 l, r;
        cin >> l >> r;

        int64 ans = 0;

        for (int k = 1; k <= MAXK; k++) {
            int64 Lk = max(l, pw10[k - 1]);
            int64 Rk = min(r, pw10[k] - 1);
            if (Lk > Rk)
                continue;

            int64 best = solve_one_k(Lk, Rk, k);
            if (best >= 0)
                ans = max(ans, best);
        }

        cout << ans << "\n";
    }

    return 0;
}
