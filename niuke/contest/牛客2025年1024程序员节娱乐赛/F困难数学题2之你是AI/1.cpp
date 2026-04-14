#include <string>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using i128 = __int128_t;

const long long MOD_INPUT = 251024;        // ȡģ
const long long MOD_OUTPUT = 998224353LL;  // ȡģ

//  1^2 + ... + n^2ʹ __int128 ֤
i128 prefix_square_sum_i128(long long n) {
    if (n <= 0) return 0;
    i128 a = (i128)n;
    i128 res = a * (a + 1) * (2 * a + 1) / 6;
    return res;
}

// ƽ [l,r]
i128 range_sum_i128(long long l, long long r) {
    if (l > r) return 0;
    return prefix_square_sum_i128(r) - prefix_square_sum_i128(l - 1);
}

// __int128 Ϊַ
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

// ȡģ
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

        // ȡģĿҪ
        l %= MOD_INPUT;
        r %= MOD_INPUT;

        // ȡģ l > rΪ 0
        if (l > r) {
            cout << 0 << '\n';
            continue;
        }

        // ƽ
        i128 ans = range_sum_i128(l, r);

        // ǰ 998224353 ȡģ
        ans = mod_output(ans);

        cout << i128_to_string(ans) << '\n';
    }

    return 0;
}
