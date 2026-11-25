#include <iostream>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll r = a % b;
        a = b, b = r;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m, g;
    cin >> n >> m >> g;

    ll d = n;
    for (int i = 0; i < m; ++i) {
        ll a;
        cin >> a;
        d = gcd(a, d);
    }

    cout << ((g % d == 0) ? "Yes" : "No") << '\n';
    return 0;
}
