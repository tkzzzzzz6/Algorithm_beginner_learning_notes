#include<bits/stdc++.h>
#include<iomanip>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, r;
    cin >> n >> r;
    ll i, j;
    cin >> i >> j;

    ll k = llabs(i - j);
    k = min(k, n - k);
    long double edge = 2.0L * r * sinl(acosl(-1.0L) / (long double)n);
    long double ans = (long double)k * edge;
    cout.setf(ios::fixed);

    cout << setprecision(6) << (double)ans << '\n';
    return 0;
}


