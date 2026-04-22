#include <bits/stdc++.h>
using namespace std;
using i128 = __int128_t;

const long long MOD_INPUT = 251024;        // 输入取模
const long long MOD_OUTPUT = 998224353LL;  // 输出取模

// 返回 1^2 + ... + n^2，使用 __int128 保证不溢出
i128 prefix_square_sum_i128(long long n) {
    if (n <= 0) return 0;
    i128 a = (i128)n;
    i128 res = a * (a + 1) * (2 * a + 1) / 6;
    return res;
}

// 区间平方和 [l,r]
i128 range_sum_i128(long long l, long long r) {
    if (l > r) return 0;
    return prefix_square_sum_i128(r) - prefix_square_sum_i128(l - 1);
}

// __int128 输出为字符串
string i128_to_string(i128 x) {
    if (x == 0) return "0";
    bool neg = x < 0;
    if (neg) x = -x;
    string s;
    while (x > 0) {
        s.push_back('0' + (int)(x % 10));
        x /= 10;
    }
    if (neg) s.push_back('-');
    reverse(s.begin(), s.end());
    return s;
}

// 对输出取模
i128 mod_output(i128 x) {
    x %= MOD_OUTPUT;
    if (x < 0) x += MOD_OUTPUT;
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        long long l, r;
        cin >> l >> r;

        // 对输入取模（题目要求）
        l %= MOD_INPUT;
        r %= MOD_INPUT;

        // 如果取模后 l > r，则答案为 0
        if (l > r) {
            cout << 0 << '\n';
            continue;
        }

        // 计算区间平方和
        i128 ans = range_sum_i128(l, r);

        // 输出前对 998224353 取模
        ans = mod_output(ans);

        cout << i128_to_string(ans) << '\n';
    }

    return 0;
}
