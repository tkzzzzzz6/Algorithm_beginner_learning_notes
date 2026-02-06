/*
 * @Author: tkzzzzzz6
 * @Date: 2026-02-03 17:13:52
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-02-03 17:13:54
 */
#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 998244353;

long long modpow(long long a, long long e) {
    long long r = 1 % MOD;
    a %= MOD;
    while (e > 0) {
        if (e & 1)
            r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long inv100 = modpow(100, MOD - 2);

    // seven-seg digit masks (7 bits). bit i means segment i is ON.
    // IMPORTANT: This mapping depends on the segment numbering in the statement.
    // You may need to adjust these masks to match the provided diagram.
    //
    // Below is a COMMON seven-seg labeling assuming segments are:
    // 0: top, 1: top-right, 2: bottom-right, 3: bottom,
    // 4: bottom-left, 5: top-left, 6: middle.
    //
    // digits:
    // 0: 0,1,2,3,4,5
    // 1: 1,2
    // 2: 0,1,6,4,3
    // 3: 0,1,6,2,3
    // 4: 5,6,1,2
    // 5: 0,5,6,2,3
    // 6: 0,5,6,2,3,4
    // 7: 0,1,2
    // 8: 0..6
    // 9: 0,1,2,3,5,6
    //
    // If the statement uses segment indices 1..7, convert accordingly.
    array<int, 10> mask = {
        (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5),            // 0
        (1 << 1) | (1 << 2),                                                        // 1
        (1 << 0) | (1 << 1) | (1 << 6) | (1 << 4) | (1 << 3),                       // 2
        (1 << 0) | (1 << 1) | (1 << 6) | (1 << 2) | (1 << 3),                       // 3
        (1 << 5) | (1 << 6) | (1 << 1) | (1 << 2),                                  // 4
        (1 << 0) | (1 << 5) | (1 << 6) | (1 << 2) | (1 << 3),                       // 5
        (1 << 0) | (1 << 5) | (1 << 6) | (1 << 2) | (1 << 3) | (1 << 4),            // 6
        (1 << 0) | (1 << 1) | (1 << 2),                                             // 7
        (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6), // 8
        (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 5) | (1 << 6)             // 9
    };

    int T;
    cin >> T;
    while (T--) {
        int C;
        cin >> C;
        vector<int> p(7);
        for (int i = 0; i < 7; i++)
            cin >> p[i];

        // convert to modular probabilities
        vector<long long> on(7), off(7);
        for (int i = 0; i < 7; i++) {
            on[i] = (long long)p[i] * inv100 % MOD;
            off[i] = (1 - on[i] + MOD) % MOD;
        }

        // prob[d] = P(display exactly digit d)
        array<long long, 10> prob{};
        for (int d = 0; d <= 9; d++) {
            long long pr = 1;
            for (int s = 0; s < 7; s++) {
                if (mask[d] & (1 << s))
                    pr = pr * on[s] % MOD;
                else
                    pr = pr * off[s] % MOD;
            }
            prob[d] = pr;
        }

        // digits of C in base 10: c[0]=ones ... c[4]=ten-thousands
        array<int, 5> c{};
        int tmp = C;
        for (int i = 0; i < 5; i++) {
            c[i] = tmp % 10;
            tmp /= 10;
        }

        // DP over 4 positions (0..3), carry in {0,1}
        long long dp[5][2];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        for (int pos = 0; pos < 4; pos++) {
            for (int carry = 0; carry <= 1; carry++) {
                long long cur = dp[pos][carry];
                if (!cur)
                    continue;
                for (int a = 0; a <= 9; a++) {
                    if (prob[a] == 0)
                        continue;
                    for (int b = 0; b <= 9; b++) {
                        if (prob[b] == 0)
                            continue;
                        int sum = a + b + carry;
                        int digit = sum % 10;
                        int ncarry = sum / 10;
                        if (digit != c[pos])
                            continue;
                        long long add = cur * prob[a] % MOD * prob[b] % MOD;
                        dp[pos + 1][ncarry] = (dp[pos + 1][ncarry] + add) % MOD;
                    }
                }
            }
        }

        // after 4 digits, the remaining carry must equal c[4], AND also c[4] must be 0/1
        long long ans = 0;
        if (c[4] == 0 || c[4] == 1)
            ans = dp[4][c[4]];
        else
            ans = 0;

        cout << ans % MOD << "\n";
    }
    return 0;
}
