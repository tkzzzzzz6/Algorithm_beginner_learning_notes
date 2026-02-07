#include <bits/stdc++.h>
#define il inline
#define endl '\n'
using namespace std;

#define pb push_back
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);

typedef long long ll;
typedef unsigned long long ull;

const ll N = 5e5 + 5, mod = 1e9 + 7, inf = 2e18;
const double eps = 1e-9;
const double PI = 3.1415926;

il void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    auto calc = [&](int startBit) -> int {
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < n; ++i) {
            int want = (i % 2 == 0) ? startBit : (startBit ^ 1);
            int cur = s[i] - '0';
            if (cur != want) {
                if (i % 2 == 0)
                    ++cnt0;
                else
                    ++cnt1;
            }
        }
        return max(cnt0, cnt1);
    };

    int ans = min(calc(0), calc(1));
    cout << ans << endl;
}
int main() {
    fastio;

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
