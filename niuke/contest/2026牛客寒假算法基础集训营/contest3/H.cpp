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

const double EPS = 1e-9;

il void solve() {
    double x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double D = y1 - y2;
    double C = x1 * y2 - x2 * y1;

    if (D == 0) {
        if (llabs(C) == 4) {
            cout << fixed << setprecision(10) << 0.0 << endl;
        } else {
            cout << "no answer" << endl;
        }
    } else {
        double x = (4.0 - (double)C) / (double)D;
        cout << fixed << setprecision(10) << x << endl;
    }
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
