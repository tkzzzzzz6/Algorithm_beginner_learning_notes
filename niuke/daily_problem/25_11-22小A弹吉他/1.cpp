#include<bits/stdc++.h>
#define il inline
using namespace std;

#define pb push_back
#define fastio \
  ios::sync_with_stdio(false); \
  cin.tie(0);

typedef long long ll;
typedef unsigned long long ull;

const ll N = 5e5+5, mod = 1e9+7, inf = 2e18;
const double eps = 1e-9;
const double PI = 3.1415926;

using i128 = __int128_t;

i128 calc(ll k)
{
    i128 kk = k;
    return kk * (kk - 1) * (kk + 1) / 6;
}

il void solve(){
    ll m;
    cin >> m;

    ll lo = 1;
    ll hi = 2000000;
    while(lo<hi)
    {
        ll mid = (lo + hi + 1) >> 1;
        if(calc(mid) <= m)
        {
            lo = mid;
        }
        else
        {
            hi = mid - 1;
        }
    }

    cout << lo << endl;
}

int main()
{
    fastio
    
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    
    return 0;
}