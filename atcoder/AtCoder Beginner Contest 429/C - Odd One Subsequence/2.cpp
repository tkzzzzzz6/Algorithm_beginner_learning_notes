#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int n;
    cin >> n;

    unordered_map<int, long long> cnt;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        cnt[a]++;
    }

    long long ans = 0;
    for (auto& [val, c] : cnt) {
        ans += c * (c - 1) / 2 * (n - c);
    }

    cout << ans << '\n';
    return 0;
}