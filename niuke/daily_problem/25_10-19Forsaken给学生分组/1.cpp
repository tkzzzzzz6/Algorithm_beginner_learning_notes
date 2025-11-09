#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n+1);
    vector<int> b(n + 1);

    for (int i = 1; i <= 2*n; ++i) {
        int x;
        cin >> x;
        if (a[x] == 0)a[x] = i;
        else b[x] = i;
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += b[i] - a[i] - 1;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a[n] > b[1])ans += 2 * (a[n] - b[1]);
    
    cout << ans << '\n';
    cout.flush();

    return 0;
}
