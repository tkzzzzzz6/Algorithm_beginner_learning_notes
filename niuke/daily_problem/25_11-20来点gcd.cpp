#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<int> cnt(n + 1, 0);
        int x;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            cnt[a]++;
        }

        vector<bool> ans(n + 1, false);

        for (int i = 1; i <= n; ++i) {
            // 1. Calculate G = gcd of all multiples of i present in S.
            int g = 0;

            // Iterate through multiples: j = i, 2i, 3i, ...
            for (int j = i; j <= n; j += i) {
                if (cnt[j] > 0) {
                    g = gcd(g, j);

                    // Early break optimization (Crucial for performance)
                    if (g == i) {
                        break;
                    }
                }
            }

            // 2. Check the condition: Is the calculated GCD exactly equal to i?
            if (g == i) {
                ans[i] = true;
            }
        }

        // Answering M queries in O(1) each.
        while (m--) {
            int x;
            cin >> x;
            if (x <= n && ans[x]) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}
