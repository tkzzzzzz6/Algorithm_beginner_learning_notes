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
    if (n % 10 == 0)
        cout << 1 << endl;
    else if (n % 2 == 0)
        cout << 5 << endl;
    else if (n % 5 == 0)
        cout << 2 << endl;
    else
        cout << 10 << endl;
}

int main() {
    fastio;

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
